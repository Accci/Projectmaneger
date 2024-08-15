#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QToolButton>
#include <QVBoxLayout>
#include "custitlebar.h"
#include <QMouseEvent>
#include "newproject.h"
#include "restore.h"
#include "tarpack.h"
#include <QTableWidget>
#include <QHeaderView>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowIcon(QIcon(":/sources/winico.ico"));
    setWindowTitle("工程管理系统");

    resize(820, 600);

    centralWidget  = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    titleWidget = new QWidget(centralWidget);
    QVBoxLayout *titleLayout = new QVBoxLayout(titleWidget);
    titleLayout->setContentsMargins(0, 0, 0, 0);
    titleLayout->setSpacing(0);

    // 添加自定义标题栏和菜单栏到布局
    CustitleBar *titlebar = new CustitleBar(titleWidget);
    connect(titlebar, &CustitleBar::minBtnClicked, this, &MainWindow::showMinimized);
    connect(titlebar, &CustitleBar::maxBtnClicked, this, &MainWindow::toggleMaximize);
    connect(titlebar, &CustitleBar::closeClicked, this, &MainWindow::close);
    titleLayout->addWidget(titlebar);
    titleLayout->addWidget(ui->menuBar);

    // 将工具栏添加到布局中
    titleLayout->addWidget(ui->mainToolBar);
    titleWidget->setFixedHeight(119);
    titleWidget->setLayout(titleLayout);

    content = new QWidget(centralWidget);
    content->setStyleSheet("background-color:white");

    mainLayout->addWidget(titleWidget);
    mainLayout->addWidget(content);

    setCentralWidget(centralWidget);
    initToolBar();
    showText();
//    showSmallPic();

}

void MainWindow::initToolBar()
{
    QAction* newPro = new QAction(QIcon(":/sources/create.png"),"新建",this);
    QToolButton *newBtn = new QToolButton();
    newBtn->setDefaultAction(newPro);
    newBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* openPro = new QAction(QIcon(":/sources/openFile.png"),"打开",this);
    QToolButton *openBtn = new QToolButton();
    openBtn->setDefaultAction(openPro);
    openBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    ui->mainToolBar->addWidget(newBtn);
    ui->mainToolBar->addWidget(openBtn);
    ui->mainToolBar->addSeparator();

    QAction* editPro = new QAction(QIcon(":/sources/edit.png"), "编辑",this);
    QToolButton *editBtn = new QToolButton();
    editBtn->setDefaultAction(editPro);
    editBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* removePro = new QAction(QIcon(":/sources/remove.png"),"删除",this);
    QToolButton *removeBtn = new QToolButton();
    removeBtn->setDefaultAction(removePro);
    removeBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* quitPro = new QAction(QIcon(":/sources/quit.png"), "退出",this);
    QToolButton *quitBtn = new QToolButton();
    quitBtn->setDefaultAction(quitPro);
    quitBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* restorePro = new QAction(QIcon(":/sources/restore.png"),"恢复",this);
    QToolButton *restoreBtn = new QToolButton();
    restoreBtn->setDefaultAction(restorePro);
    restoreBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* copyPro = new QAction(QIcon(":/sources/copy.png"), "备份",this);
    QToolButton *copyBtn = new QToolButton();
    copyBtn->setDefaultAction(copyPro);
    copyBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* tarPro = new QAction(QIcon(":/sources/tar.png"),"打包",this);
    QToolButton *tarBtn = new QToolButton();
    tarBtn->setDefaultAction(tarPro);
    tarBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->mainToolBar->addWidget(editBtn);
    ui->mainToolBar->addWidget(removeBtn);
    ui->mainToolBar->addWidget(quitBtn);
    ui->mainToolBar->addWidget(restoreBtn);
    ui->mainToolBar->addWidget(copyBtn);
    ui->mainToolBar->addWidget(tarBtn);

    ui->mainToolBar->addSeparator();
    QAction* superbigPro = new QAction(QIcon(":/sources/superbig.png"), "超大",this);
    QToolButton *superbigBtn = new QToolButton();
    superbigBtn->setDefaultAction(superbigPro);
    superbigBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* bigPro = new QAction(QIcon(":/sources/big.png"),"大图",this);
    QToolButton *bigBtn = new QToolButton();
    bigBtn->setDefaultAction(bigPro);
    bigBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* smallPro = new QAction(QIcon(":/sources/small.png"),"小图",this);
    QToolButton *smallBtn = new QToolButton();
    smallBtn->setDefaultAction(smallPro);
    smallBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->mainToolBar->addWidget(superbigBtn);
    ui->mainToolBar->addWidget(bigBtn);
    ui->mainToolBar->addWidget(smallBtn);
    ui->mainToolBar->addSeparator();
    QAction* listPro = new QAction(QIcon(":/sources/list.png"),"列表",this);
    QToolButton *listBtn = new QToolButton();
    listBtn->setDefaultAction(listPro);
    listBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* detailPro = new QAction(QIcon(":/sources/detail.png"),"详细",this);
    QToolButton *detailBtn = new QToolButton();
    detailBtn->setDefaultAction(detailPro);
    detailBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->mainToolBar->addWidget(listBtn);
    ui->mainToolBar->addWidget(detailBtn);
    ui->mainToolBar->addSeparator();

    QAction* runPro = new QAction(QIcon(":/sources/run.png"),"运行",this);
    QToolButton *runBtn = new QToolButton();
    runBtn->setDefaultAction(runPro);
    runBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    QAction* studyPro = new QAction(QIcon(":/sources/study.png"),"开发",this);
    QToolButton *studyBtn = new QToolButton();
    studyBtn->setDefaultAction(studyPro);
    studyBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    ui->mainToolBar->addWidget(runBtn);
    ui->mainToolBar->addWidget(studyBtn);
    ui->mainToolBar->setStyleSheet(
                                   "border-bottom:2px solid #c3c3c3;"
                                   );


    ui->mainToolBar->setMovable(false);

    connect(newBtn, &QToolButton::clicked, this, &MainWindow::showNewPro);
    connect(restoreBtn, &QToolButton::clicked, this, &MainWindow::showRestore);
    connect(tarBtn, &QToolButton::clicked, this, &MainWindow::showTar);
    connect(superbigBtn, &QToolButton::clicked, this, &MainWindow::showSuperbigPic);
    connect(bigBtn, &QToolButton::clicked, this, &MainWindow::showbigPic);
    connect(smallBtn, &QToolButton::clicked, this, &MainWindow::showSmallPic);
    connect(detailBtn, &QToolButton::clicked,this, &MainWindow::showText);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   if(event->button() == Qt::LeftButton)
   {
       dragging = true;
       dragPos = event->globalPos()-frameGeometry().topLeft();
       event->accept();
   }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    dragging = false;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(dragging && (event->buttons() & Qt::LeftButton))
    {
        move(event->globalPos()-dragPos);
        event->accept();
    }
}

void MainWindow::toggleMaximize()
{
    if(isMaximized())
        showNormal();
    else {
        showMaximized();
    }
}

void MainWindow::showNewPro()
{
    NewProject np;
    np.exec();
}

void MainWindow::showRestore()
{
    Restore restore;
    restore.exec();
}

void MainWindow::showTar()
{
    TarPack pack;
    pack.exec();
}

void MainWindow::showSuperbigPic()
{
    clearContent();

    QVBoxLayout *layout = new QVBoxLayout(content);
    QQuickWidget *quickWidget = new QQuickWidget(this);
    quickWidget->setSource(QUrl(QStringLiteral("qrc:/superBig.qml")));
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    layout->addWidget(quickWidget);

}

void MainWindow::showbigPic()
{
    clearContent();

     QVBoxLayout *layout = new QVBoxLayout(content);
     QQuickWidget *quickWidget = new QQuickWidget(this);
     quickWidget->setSource(QUrl(QStringLiteral("qrc:/big.qml")));
     quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
     layout->addWidget(quickWidget);
}

void MainWindow::showSmallPic()
{
     clearContent();

    QVBoxLayout *layout = new QVBoxLayout(content);
    QQuickWidget *quickWidget = new QQuickWidget(this);
    quickWidget->setSource(QUrl(QStringLiteral("qrc:/small.qml")));
    quickWidget->setResizeMode(QQuickWidget::SizeRootObjectToView);
    layout->addWidget(quickWidget);
}

void MainWindow::showText()
{
    clearContent();
//    ui->mainToolBar->setStyleSheet(
//                                   "border-bottom:2px solid #eaecf0;"
//                                   );
    QVBoxLayout *layout = new QVBoxLayout(content);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    QTableWidget *tableWidget = new QTableWidget(content);
    tableWidget->setColumnCount(7);

    QStringList headers;
    headers<< "工程ID" << "工程名称" << "路径" << "分辨率" << "版本" << "时间" << "描述";
    tableWidget->setHorizontalHeaderLabels(headers);
    tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




    QFile file("../test.txt");
    if(!file.open(QIODevice::ReadOnly |QIODevice::Text))
    {
        qWarning("Failed to open file.");
        return;
    }

    QTextStream in(&file);
    int row = 0;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QRegularExpression regex(R"(([^ ]+)\s+([^ ]+)\s+([^\s]+(?: [^\s]+)*)\s+([^\s]+)\s+([^\s]+)\s+([^\s]+\s+[^\s]+)\s+(.*))");
        QRegularExpressionMatch match = regex.match(line);

        if(match.hasMatch())
        {
           tableWidget->insertRow(row);
           tableWidget->setItem(row, 0, new QTableWidgetItem(match.captured(1)));
           tableWidget->setItem(row, 1, new QTableWidgetItem(match.captured(2)));
           tableWidget->setItem(row, 2, new QTableWidgetItem(match.captured(3)));
           tableWidget->setItem(row, 3, new QTableWidgetItem(match.captured(4)));
           tableWidget->setItem(row, 4, new QTableWidgetItem(match.captured(5)));
           tableWidget->setItem(row, 5, new QTableWidgetItem(match.captured(6)));
           tableWidget->setItem(row, 6, new QTableWidgetItem(match.captured(7)));
           ++row;
        }
    }


    for (int i = 0; i < tableWidget->columnCount(); ++i) {
           tableWidget->horizontalHeader()->setSectionResizeMode(i, QHeaderView::Stretch);
       }
    tableWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QHeaderView *header = tableWidget->horizontalHeader();
    header->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);

    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    file.close();
    tableWidget->verticalHeader()->setVisible(false);
    tableWidget->horizontalHeader()->setStyleSheet(
           "QHeaderView::section {"
           "    background-color: #eaecf0;"  // 表头背景颜色
           "    color: #000000;"  // 表头文本颜色
           "    border: none;"  // 移除其他边框
           "    border-bottom: 2px solid #e1e2e6;"  // 只设置下边框
           "    padding-left: 10px;"  // 减少内边距
           "    text-align: left;"  // 文本左对齐
           "}"
       );

    tableWidget->setStyleSheet(
                "QTableWidget {"
                    "    border: none;"  // 移除QTableWidget的边框
                    "    gridline-color: #d0d0d0;"  // 网格线颜色
                    "    color: black;"  // 文本颜色
                    "    font-size: 12px;"
                    "}"
                    "QTableWidget::item {"
                    "    padding-left: 10px;"  // 设置数据与单元格边框的间距
                    "    background-color: #ffffff;"  // 默认背景颜色
                    "}"
                    "QTableWidget::item:selected {"
                    "    background-color: #f4f4f4;"  // 选中行的背景色
                    "    padding-left: 10px;"  // 确保选中项也有相同的填充
                    "    color:black;"
                    "}"
                );


    layout->addWidget(tableWidget);
    content->setLayout(layout);
}

void MainWindow::clearContent()
{
    // 清除所有子组件
        QList<QWidget*> widgets = content->findChildren<QWidget*>();
        foreach (QWidget* widget, widgets) {
            widget->deleteLater();  // 标记组件为待删除
        }

        // 清除布局
        QLayout *layout = content->layout();
        if (layout) {
            QLayoutItem *item;
            while ((item = layout->takeAt(0)) != nullptr) {
                QWidget *widget = item->widget();
                if (widget) {
                    widget->deleteLater();  // 标记组件为待删除
                }
                delete item;  // 删除布局项
            }
            delete layout;  // 删除布局
        }

        content->update();  // 强制刷新 content
}

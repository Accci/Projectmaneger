#include "newproject.h"
#include <QIcon>
#include <QFileDialog>
#include <QDebug>
#include "selecttemplate.h"

NewProject::NewProject(QWidget *parent) : QDialog(parent)
{
    setWindowTitle("新建工程");
    setFont(QFont("黑体",12));
    setWindowIcon(QIcon(":/sources/winico.ico"));
    initControl();
    setLayout(mlayout);
    setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    setFixedSize(400, 450);
}

void NewProject::initControl()
{

    mtype = new QLabel("工程类型");

    mtype->setTextInteractionFlags(Qt::NoTextInteraction);

    mNewPro = new QRadioButton("新建工程",this);
    mTemplatePro = new QRadioButton("模板工程", this);
    QHBoxLayout *radioLayout = new QHBoxLayout();
    radioLayout->setContentsMargins(8,0,0,0);


    radioLayout->addWidget(mNewPro);
    radioLayout->addWidget(mTemplatePro);
    mlayout = new QVBoxLayout(this);
    mlayout->addWidget(mtype);
    mtype->setIndent(8);
    mlayout->setSpacing(10);
    mlayout->addLayout(radioLayout);

    mstackedWidget = new QStackedWidget(this);
    QWidget* newProPage = createNewProPage();
    QWidget* templateProPage = createTemplateProPage();

    mstackedWidget->addWidget(newProPage);
    mstackedWidget->addWidget(templateProPage);
    mlayout->addWidget(mstackedWidget);


    connect(mNewPro, &QRadioButton::toggled, this, [this](){
        if(mNewPro->isChecked())
        {
            mstackedWidget->setCurrentIndex(0);
        }
    });

    connect(mTemplatePro, &QRadioButton::toggled, this, [this](){

        if(mTemplatePro->isChecked())
        {
            mstackedWidget->setCurrentIndex(1);
        }
    });


    return;
}

QWidget *NewProject::createNewProPage()
{
    QWidget *newPage = new QWidget(this);
    QVBoxLayout *newPageLayout = new QVBoxLayout(newPage);

    QLabel *proName = new QLabel("工程名称");
    proName->setTextInteractionFlags(Qt::NoTextInteraction);
    QLineEdit *name = new QLineEdit(this);
    name->setFixedHeight(30);
    newPageLayout->addWidget(proName);
    newPageLayout->addWidget(name);

    QLabel *proPath = new QLabel("工程路径", this);
    proPath->setTextInteractionFlags(Qt::NoTextInteraction);
    newPageLayout->addWidget(proPath);

    QHBoxLayout *pathLayout = new QHBoxLayout();
    QLineEdit *path = new QLineEdit(this);
    path->setFixedHeight(30);
    QPushButton *selectPath = new QPushButton("...", this);
    selectPath->setFixedSize(50, 30);
    connect(selectPath, &QPushButton::clicked, this, [path](){
        QString dir = QFileDialog::getExistingDirectory(nullptr, "选择工程路径");
//        qDebug() << "Selected Directory:" << dir;  // 调试输出
        if(!dir.isEmpty())
        {
            path->setText(dir);
//            qDebug() << "Path set to:" << path->text();  // 检查赋值
        }
    });

    pathLayout->addWidget(path);
    pathLayout->addWidget(selectPath);
    newPageLayout->addLayout(pathLayout);

    QLabel *resolution = new QLabel("分辨率", this);
    QLabel *width = new QLabel("宽度(W)", this);
    QLabel *height = new QLabel("高度(H)", this);
    QHBoxLayout *resLayout = new QHBoxLayout();
    resLayout->addWidget(resolution);
    resLayout->addWidget(width);
    resLayout->addWidget(height);
    newPageLayout->addLayout(resLayout);

    QHBoxLayout *resLayout1 = new QHBoxLayout();
    QComboBox *selectRes = new QComboBox(this);
    selectRes->setFixedSize(130, 30);
    QLineEdit *w = new QLineEdit(this);
    QLineEdit *h = new QLineEdit(this);

    selectRes->addItem("1920x1080");
    selectRes->addItem("1280x720");
    selectRes->addItem("1366x768");
    selectRes->addItem("2560x1440");
    selectRes->addItem("3840x2160");
    selectRes->addItem("自定义分辨率");

    connect(selectRes, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [w, h](int index){
        switch (index)
        {
        case 0:
            w->setText("1920");
            h->setText("1080");
            break;
        case 1:
            w->setText("1280");
            h->setText("720");
            break;
        case 2:
            w->setText("1366");
            h->setText("768");
            break;
        case 3:
            w->setText("2560");
            h->setText("1440");
            break;
        case 4:
            w->setText("3840");
            h->setText("2160");
            break;
        default:
            w->clear();
            h->clear();
            break;
        }
    });

    w->setFixedHeight(30);
    h->setFixedHeight(30);
    resLayout1->addWidget(selectRes);
    resLayout1->addWidget(w);
    resLayout1->addWidget(h);
    w->setText("1920");
    h->setText("1080");

    newPageLayout->addLayout(resLayout1);

    QLabel *description = new QLabel("工程描述",this);
    QLineEdit *des = new QLineEdit(this);
    des->setFixedHeight(30);
    newPageLayout->addWidget(description);
    newPageLayout->addWidget(des);
    newPageLayout->setSpacing(10);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    QPushButton *cancleBtn = new QPushButton("取消", this);
    QPushButton *okBtn = new QPushButton("确定", this);
    cancleBtn->setFixedSize(70, 30);
    okBtn->setFixedSize(70, 30);
    buttonLayout->addWidget(cancleBtn);
    buttonLayout->addWidget(okBtn);
    newPageLayout->addLayout(buttonLayout);
    return newPage;
}

QWidget *NewProject::createTemplateProPage()
{
    QWidget *newTempPage = new QWidget(this);
    QVBoxLayout *newTempPageLayout = new QVBoxLayout(newTempPage);

    newTempPageLayout->addWidget(new QLabel("选择模板", this));
    QHBoxLayout *templateLayout = new QHBoxLayout();
    QLineEdit *templatePath = new QLineEdit(this);
    templatePath->setFixedHeight(30);
    templatePath->setReadOnly(true);
    templateLayout->addWidget(templatePath);
    QPushButton *TmpBtn = new QPushButton(this);
    TmpBtn->setText("...");
    TmpBtn->setFixedSize(50 ,30);
    connect(TmpBtn, &QPushButton::clicked, this, [templatePath]() {
        SelectTemplate temp;
       if(temp.exec() == QDialog::Accepted)
       {
           QString str = temp.getSelectTemp();
           if(!str.isEmpty())
           {
               templatePath->setText(str);
           }
       }
    });
    templateLayout->addWidget(TmpBtn);
    newTempPageLayout->addLayout(templateLayout);

    QLabel *proName = new QLabel("工程名称");
    proName->setTextInteractionFlags(Qt::NoTextInteraction);
    QLineEdit *name = new QLineEdit(this);
    name->setFixedHeight(30);
    newTempPageLayout->addWidget(proName);
    newTempPageLayout->addWidget(name);

    QLabel *proPath = new QLabel("工程路径", this);
    proPath->setTextInteractionFlags(Qt::NoTextInteraction);
    newTempPageLayout->addWidget(proPath);

    QHBoxLayout *pathLayout = new QHBoxLayout();
    QLineEdit *path = new QLineEdit(this);
    path->setFixedHeight(30);
    QPushButton *selectPath = new QPushButton("...", this);
    selectPath->setFixedSize(50 ,30);
    connect(selectPath, &QPushButton::clicked, this, [path](){
        QString dir = QFileDialog::getExistingDirectory(nullptr, "选择工程路径");
        if(!dir.isEmpty())
        {
            path->setText(dir);
        }
    });
    pathLayout->addWidget(path);
    pathLayout->addWidget(selectPath);
    newTempPageLayout->addLayout(pathLayout);

    QLabel *resolution = new QLabel("分辨率", this);
    QLabel *width = new QLabel("宽度(W)", this);
    QLabel *height = new QLabel("高度(H)", this);
    QHBoxLayout *resLayout = new QHBoxLayout();
    resLayout->addWidget(resolution);
    resLayout->addWidget(width);
    resLayout->addWidget(height);
    newTempPageLayout->addLayout(resLayout);

    QHBoxLayout *resLayout1 = new QHBoxLayout();
    QComboBox *selectRes = new QComboBox(this);
    QLineEdit *w = new QLineEdit(this);
    QLineEdit *h = new QLineEdit(this);

    selectRes->addItem("1920x1080");
    selectRes->addItem("1280x720");
    selectRes->addItem("3840x2160");
    selectRes->addItem("2560x1440");
    selectRes->addItem("1366x768");
    selectRes->addItem("自定义分辨率");

    connect(selectRes, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [w, h](int index){
        switch (index)
        {
        case 0:
            w->setText("1920");
            h->setText("1080");
            break;
        case 1:
            w->setText("1280");
            h->setText("720");
            break;
        case 2:
            w->setText("1366");
            h->setText("768");
            break;
        case 3:
            w->setText("2560");
            h->setText("1440");
            break;
        case 4:
            w->setText("3840");
            h->setText("2160");
            break;
        default:
            w->clear();
            h->clear();
            break;
        }
    });

    selectRes->setFixedSize(130, 30);
    w->setFixedHeight(30);
    h->setFixedHeight(30);
    resLayout1->addWidget(selectRes);
    resLayout1->addWidget(w);
    resLayout1->addWidget(h);
    w->setText("1920");
    h->setText("1080");
    newTempPageLayout->addLayout(resLayout1);

    QLabel *description = new QLabel("工程描述",this);
    QLineEdit *des = new QLineEdit(this);
    des->setFixedHeight(30);
    newTempPageLayout->addWidget(description);
    newTempPageLayout->addWidget(des);

    newTempPageLayout->setSpacing(10);
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    QPushButton *cancleBtn = new QPushButton("取消", this);
    QPushButton *okBtn = new QPushButton("确定", this);
    cancleBtn->setFixedSize(60, 30);
    okBtn->setFixedSize(60, 30);
    buttonLayout->addWidget(cancleBtn);
    buttonLayout->addWidget(okBtn);
    newTempPageLayout->addLayout(buttonLayout);
    return newTempPage;
}





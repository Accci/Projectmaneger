#include "tarpack.h"
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QFileDialog>
TarPack::TarPack(QWidget *parent) : QDialog(parent)
{
    setFont(QFont("黑体",12));
    setWindowTitle("工程打包");
    setWindowIcon(QIcon(":/sources/ico.png"));
    setWindowFlags(windowFlags()& ~Qt::WindowContextHelpButtonHint);
    layout = new QVBoxLayout(this);
    setFixedSize(400, 450);
    initControl();
}

void TarPack::initControl()
{
    QLabel *savePath = new QLabel("安装包存放路径", this);
    QHBoxLayout* pathLayout = new QHBoxLayout;
    QLineEdit *savePathLineEdit = new QLineEdit;
    savePathLineEdit->setFixedHeight(30);
    QPushButton *pathBtn = new QPushButton("...", this);
    pathBtn->setFixedSize(50, 30);
    pathLayout->addWidget(savePathLineEdit);
    pathLayout->addWidget(pathBtn);
    connect(pathBtn, &QPushButton::clicked, this, [savePathLineEdit](){
        QString dir = QFileDialog::getExistingDirectory(nullptr, "选择存储路径");
        if(!dir.isEmpty())
        {
            savePathLineEdit->setText(dir);
        }
    });
    layout->addWidget(savePath);
    layout->addLayout(pathLayout);

    QLabel *title = new QLabel("安装包运行时窗口的标题",this);
    QLineEdit *titleLineEdit = new QLineEdit;
    titleLineEdit->setFixedHeight(30);

    layout->addWidget(title);
    layout->addWidget(titleLineEdit);

    QLabel *runPath = new QLabel("安装包运行时缺省安装路径", this);
    QHBoxLayout* runPathLayout = new QHBoxLayout;
    QLineEdit *runPathLineEdit = new QLineEdit;
    runPathLineEdit->setFixedHeight(30);
    QPushButton *runPathBtn = new QPushButton("...", this);
    runPathBtn->setFixedSize(50, 30);
    runPathLayout->addWidget(runPathLineEdit);
    runPathLayout->addWidget(runPathBtn);

    connect(runPathBtn, &QPushButton::clicked, this, [runPathLineEdit](){
        QString dir = QFileDialog::getExistingDirectory(nullptr, "选择存储路径");
        if(!dir.isEmpty())
        {
            runPathLineEdit->setText(dir);
        }
    });
    layout->addWidget(runPath);
    layout->addLayout(runPathLayout);

    QLabel *shortCut = new QLabel("安装完成后的快捷方式名",this);
    QLineEdit *shortCutLineEdit = new QLineEdit;
    shortCutLineEdit->setFixedHeight(30);

    layout->addWidget(shortCut);
    layout->addWidget(shortCutLineEdit);


    QLabel *tarPack = new QLabel("正在打包", this);
    QProgressBar *packBar = new QProgressBar(this);
    packBar->setRange(0,200);
    packBar->setValue(50);

    packBar->setFixedHeight(20);
    packBar->setTextVisible(false);
    layout->addWidget(tarPack);
    layout->addWidget(packBar);
    layout->addSpacing(20);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    QPushButton *cancleBtn = new QPushButton("取消");
    QPushButton *okBtn = new QPushButton("确定");
    cancleBtn->setFixedSize(70,30);
    okBtn->setFixedSize(70,30);
    buttonLayout->addWidget(cancleBtn);
    buttonLayout->addWidget(okBtn);

    connect(cancleBtn, &QPushButton::clicked, this, &QDialog::reject);
    connect(okBtn, &QPushButton::clicked, this, &QDialog::accept);

    layout->addLayout(buttonLayout);
}



#include "restore.h"
#include <QIcon>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QFileDialog>
Restore::Restore( QDialog* parent):QDialog (parent)
{
    setWindowTitle("工程恢复");
    setWindowIcon(QIcon(":/sources/ico.png"));
    setFont(QFont("黑体",12));
    setWindowFlags(windowFlags()& ~Qt::WindowContextHelpButtonHint);
    setFixedSize(400, 300);

    layout = new QVBoxLayout(this);
    initControl();
}

void Restore::initControl()
{
    QLabel* passwd = new QLabel("工程密码",this);
    QLineEdit* passwdEdit = new QLineEdit;
    passwdEdit->setFixedHeight(30);
    layout->addWidget(passwd);
    layout->addWidget(passwdEdit);


    QLabel *path = new QLabel("工程路径",this);
    QHBoxLayout*pathLayout = new QHBoxLayout();

    QLineEdit *pathLineEdit = new QLineEdit(this);
    pathLineEdit->setFixedHeight(30);
    QPushButton *pathBtn = new QPushButton("...",this);
    pathBtn->setFixedSize(50, 30);
    connect(pathBtn, &QPushButton::clicked, this, [pathLineEdit](){
        QString dir = QFileDialog::getExistingDirectory(nullptr, "选择工程路径");
        if(!dir.isEmpty())
        {
            pathLineEdit->setText(dir);
        }
    });
    pathLayout->addWidget(pathLineEdit);
    pathLayout->addWidget(pathBtn);

    layout->addWidget(path);
    layout->addLayout(pathLayout);


    QLabel *restore = new QLabel("工程恢复中", this);
    QProgressBar *proBar = new QProgressBar(this);
    proBar->setRange(0,200);
    proBar->setValue(50);

    proBar->setFixedHeight(20);
    proBar->setTextVisible(false);
    layout->addWidget(restore);
    layout->addWidget(proBar);
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

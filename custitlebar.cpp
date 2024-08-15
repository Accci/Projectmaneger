#include "custitlebar.h"
#include <QHBoxLayout>
#define BTN_W 23
#define BTN_H 23
#define TITLE_H 35
CustitleBar::CustitleBar(QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *titlelayout = new QHBoxLayout(this);
    titlelayout->setContentsMargins(0, 0, 0, 0);
    titlelayout->setSpacing(0);

    mwidget = new QWidget(this);
    mwidget->setFixedHeight(TITLE_H);

    mIco = new QLabel(mwidget);
    mContent = new QLabel(mwidget);

    minBtn = new QPushButton("-", mwidget);
    maxBtn =  new QPushButton("□", mwidget);
    closeBtn =  new QPushButton("×", mwidget);

    mwidget->setStyleSheet("QPushButton {"
                                 "color: white;" // 设置文字颜色为白色
                                 "border: none;" // 取消边框
                                 "background: transparent;" // 使背景透明
                                 "}");

    minBtn->setFixedSize(BTN_W, BTN_H);
    maxBtn->setFixedSize(BTN_W, BTN_H);
    closeBtn->setFixedSize(BTN_W, BTN_H);

    mlayout = new QHBoxLayout(mwidget);
    mlayout->setContentsMargins(5, 0, 0, 0);		//设置布局间的间隙
    mlayout->setSpacing(0);

    mlayout->addWidget(mIco);
    mlayout->addWidget(mContent);
    mIco->setPixmap(QPixmap(":/sources/ico.png"));
    mContent->setText("工程管理系统");
    mContent->setFont(QFont("黑体",12));
    mContent->setStyleSheet("color:white");

    mlayout->addStretch();
    mlayout->addWidget(minBtn);
    mlayout->addWidget(maxBtn);
    mlayout->addWidget(closeBtn);

    mwidget->setLayout(mlayout);
    mwidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    titlelayout->addWidget(mwidget);

    setLayout(titlelayout);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setStyleSheet("background-color: #3b576e;");

    initConnections();
}

void CustitleBar::initConnections()
{
    connect(minBtn, &QPushButton::clicked, this, &CustitleBar::onMinBtnClicked);
    connect(maxBtn, &QPushButton::clicked, this, &CustitleBar::onMaxBtnClicked);
    connect(closeBtn, &QPushButton::clicked, this, &CustitleBar::onCloseClicked);
}


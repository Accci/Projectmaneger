#include "customtitlebar.h"

#define BUTTON_WIDTH 23
#define BUTTON_HEIGHT 23
#define TITLE_HEIGHT 40
CustomTitleBar::CustomTitleBar(QWidget *parent) : QWidget(parent)
{


    initControl();
}

void CustomTitleBar::initControl()
{
    m_pIcon = new QLabel(this);
    m_pIcon->setPixmap(QPixmap(":/sources/winico.ico"));
    m_PtitleContent = new QLabel(this);

    m_PtitleContent->setText("工程管理系统");
    m_PtitleContent->setStyleSheet("color: white");

    m_minBtn = new QPushButton(this);
    m_maxBtn = new QPushButton(this);
    m_closeBtn = new QPushButton(this);

    m_minBtn->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    m_maxBtn->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    m_closeBtn->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    m_minBtn->setIcon(QIcon(":/sources/min.png"));
    m_maxBtn->setIcon(QIcon(":/sources/max.png"));
    m_maxBtn->setIcon(QIcon(":/sources/close.png"));

    m_minBtn->setStyleSheet("color: white");
    m_maxBtn->setStyleSheet("color:white");
    m_closeBtn->setStyleSheet("color:white");

    m_layout = new QHBoxLayout(this);
    m_layout->addWidget(m_pIcon);
    m_layout->addWidget(m_PtitleContent);

    m_layout->addStretch();
    m_layout->addWidget(m_minBtn);
    m_layout->addWidget(m_maxBtn);
    m_layout->addWidget(m_closeBtn);
    setLayout(m_layout);
    setStyleSheet("background-color: #3b576e;");

    setFixedHeight(TITLE_HEIGHT);
    setFixedWidth(800);
    setWindowFlags(Qt::FramelessWindowHint);
}

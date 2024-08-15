#include "selecttemplate.h"
#include <QIcon>
#include <QLabel>

#include <QVBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMap>
static const QMap<int, QString> numberMap = {
        {1, "一"},
        {2, "二"},
        {3, "三"},
        {4, "四"},
        {5, "五"},
        {6, "六"},
        {7, "七"},
        {8, "八"},
        {9, "九"},
        {10, "十"}
    };
SelectTemplate::SelectTemplate(QDialog*parent):QDialog (parent)
{
    setWindowTitle("选择模板");
    setFont(QFont("黑体",12));
    setWindowIcon(QIcon(":/sources/ico.png"));
    setWindowFlags(windowFlags() &~Qt::WindowContextHelpButtonHint);

    QGridLayout *gridLayout = new QGridLayout;
    for(int i = 0; i < 6; ++i)
    {
         QLabel *imgLabel = new QLabel;
         imgLabel->setPixmap(QPixmap(":/sources/temp.png").scaled(200,120, Qt::KeepAspectRatio));
         QRadioButton *radioBtn = new QRadioButton(QString("模板%1").arg(numberMap[i+1]));
         radioBtns.append(radioBtn);
         QVBoxLayout *vbox = new QVBoxLayout;
         vbox->addWidget(imgLabel);
         vbox->addWidget(radioBtn);
         gridLayout->addLayout(vbox, i/3, i%3);
    }

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addStretch();
    QPushButton *cancleBtn = new QPushButton("取消");
    QPushButton *okBtn = new QPushButton("确定");

    buttonLayout->addWidget(cancleBtn);
    buttonLayout->addWidget(okBtn);

    connect(cancleBtn, &QPushButton::clicked, this, &QDialog::reject);
    connect(okBtn, &QPushButton::clicked, this, &QDialog::accept);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gridLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

QString SelectTemplate::getSelectTemp() const
{
    for(QRadioButton *radioBtn : radioBtns)
    {
        if(radioBtn->isChecked())
        {
            return radioBtn->text();
        }
    }
    return  QString();
}

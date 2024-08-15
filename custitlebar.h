#ifndef CUSTITLEBAR_H
#define CUSTITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
class CustitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit CustitleBar(QWidget *parent = nullptr);
    void initConnections();

signals:
    void minBtnClicked();
    void maxBtnClicked();
    void closeClicked();
public slots:
    void onMinBtnClicked(){emit minBtnClicked();}
    void onMaxBtnClicked(){emit maxBtnClicked();}
    void onCloseClicked(){emit closeClicked();}

private:
    QLabel* mIco;
    QLabel* mContent;
    QPushButton* minBtn;
    QPushButton* maxBtn;
    QPushButton* closeBtn;
    QHBoxLayout* mlayout;
    QWidget *mwidget;

};

#endif // CUSTITLEBAR_H

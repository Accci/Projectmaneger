#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>
#include <QRadioButton>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QStackedWidget>
class NewProject : public QDialog
{
    Q_OBJECT
public:
    explicit NewProject(QWidget *parent = nullptr);

signals:

public slots:
private:
    void initControl();
    QWidget* createNewProPage();
    QWidget* createTemplateProPage();
    void setWidgetsHeight(QLayout *layout, int height);
private:
    QLabel* mtype;
    QRadioButton *mNewPro;
    QRadioButton *mTemplatePro;
    QVBoxLayout *mlayout;
    QStackedWidget *mstackedWidget;

};

#endif // NEWPROJECT_H

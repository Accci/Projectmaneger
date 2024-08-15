#ifndef SELECTTEMPLATE_H
#define SELECTTEMPLATE_H

#include <QObject>
#include <QDialog>
#include <QRadioButton>

class SelectTemplate : public QDialog
{
    Q_OBJECT
public:
    SelectTemplate(QDialog* parent=nullptr);
    QString getSelectTemp()const;
private:
    QList<QRadioButton*> radioBtns;
};

#endif // SELECTTEMPLATE_H

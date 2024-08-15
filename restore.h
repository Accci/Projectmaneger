#ifndef RESTORE_H
#define RESTORE_H

#include <QDialog>
#include <QVBoxLayout>

class Restore : public QDialog
{
    Q_OBJECT
public:
    Restore( QDialog* parent = nullptr);

private:
    void initControl();
private:
    QVBoxLayout *layout;
};

#endif // RESTORE_H

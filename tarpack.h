#ifndef TARPACK_H
#define TARPACK_H

#include <QDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
class TarPack : public QDialog
{
    Q_OBJECT
public:
    explicit TarPack(QWidget *parent = nullptr);
private:
    void initControl();
    QVBoxLayout *layout;
};

#endif // TARPACK_H

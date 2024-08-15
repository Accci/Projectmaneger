#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow()override;

protected:
    void mousePressEvent(QMouseEvent* event)override;
    void mouseReleaseEvent(QMouseEvent* event)override;
    void mouseMoveEvent(QMouseEvent* event)override;
private slots:
    void toggleMaximize();
    void showNewPro();
    void showRestore();
    void showTar();
    void showSuperbigPic();
    void showbigPic();
    void showSmallPic();
    void showText();

    void clearContent();
private:
    void initToolBar();


private:
    Ui::MainWindow *ui;
    QWidget *centralWidget;
    QWidget *titleWidget;
    QWidget *content;
//    QQuickWidget *quickWidget;
    bool dragging = false;
    QPoint dragPos;
};




#endif // MAINWINDOW_H

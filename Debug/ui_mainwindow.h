/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *newAction;
    QAction *openAction;
    QAction *inputAction;
    QAction *outputAction;
    QAction *saveAction;
    QAction *quitAction;
    QAction *closeAction;
    QWidget *centralWidget;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow::separator { width: 0px; height: 0px; }"));
        newAction = new QAction(MainWindow);
        newAction->setObjectName(QString::fromUtf8("newAction"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/sources/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        newAction->setIcon(icon);
        newAction->setShortcutVisibleInContextMenu(true);
        openAction = new QAction(MainWindow);
        openAction->setObjectName(QString::fromUtf8("openAction"));
        inputAction = new QAction(MainWindow);
        inputAction->setObjectName(QString::fromUtf8("inputAction"));
        outputAction = new QAction(MainWindow);
        outputAction->setObjectName(QString::fromUtf8("outputAction"));
        saveAction = new QAction(MainWindow);
        saveAction->setObjectName(QString::fromUtf8("saveAction"));
        quitAction = new QAction(MainWindow);
        quitAction->setObjectName(QString::fromUtf8("quitAction"));
        closeAction = new QAction(MainWindow);
        closeAction->setObjectName(QString::fromUtf8("closeAction"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(0, 60));
        mainToolBar->setMaximumSize(QSize(16777215, 60));
        mainToolBar->setToolTipDuration(-1);
        mainToolBar->setStyleSheet(QString::fromUtf8(""));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy);
        menuBar->setMinimumSize(QSize(0, 23));
        menuBar->setMaximumSize(QSize(16777215, 23));
        menuBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        menuBar->setToolTipDuration(-1);
        menuBar->setAutoFillBackground(false);
        menuBar->setStyleSheet(QString::fromUtf8("\n"
"QMenuBar{background-color:#f0f0f0;}\n"
"QMenuBar::Item:selected{background-color:#346093; }"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setStyleSheet(QString::fromUtf8("QMenu::item:selected {\n"
"    background-color: #335f91; \n"
"    color: white; \n"
"}"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(newAction);
        menu->addAction(openAction);
        menu->addAction(closeAction);
        menu->addSeparator();
        menu->addAction(inputAction);
        menu->addAction(outputAction);
        menu->addAction(saveAction);
        menu->addSeparator();
        menu->addAction(quitAction);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        newAction->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\345\267\245\347\250\213", nullptr));
#ifndef QT_NO_SHORTCUT
        newAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        openAction->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\267\245\347\250\213", nullptr));
#ifndef QT_NO_SHORTCUT
        openAction->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        inputAction->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245", nullptr));
        outputAction->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272", nullptr));
        saveAction->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        quitAction->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
        closeAction->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255\345\267\245\347\250\213", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\345\267\245\347\250\213", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

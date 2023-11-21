/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionSave_as_Image;
    QAction *actionQuit;
    QAction *actionAbout_Me;
    QWidget *centralwidget;
    QTreeView *tools;
    QPushButton *toolCircle;
    GLWidget *widget;
    QPushButton *pushButton_7;
    QPushButton *toolPen;
    QPushButton *toolSquare;
    QPushButton *colorBlue;
    QPushButton *colorPurple;
    QPushButton *colorRed;
    QPushButton *colorGreen;
    QPushButton *colorBlack;
    QPushButton *colorWhite;
    QSpinBox *fontSize;
    QLabel *label;
    QPushButton *toolLine;
    QPushButton *toolEraser;
    QPushButton *toolText;
    QPushButton *toolSpray;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        QString iconThemeName = QString::fromUtf8("window-new");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionNew->setIcon(icon1);
        actionSave_as_Image = new QAction(MainWindow);
        actionSave_as_Image->setObjectName(QString::fromUtf8("actionSave_as_Image"));
        QIcon icon2;
        iconThemeName = QString::fromUtf8("media-floppy");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon2 = QIcon::fromTheme(iconThemeName);
        } else {
            icon2.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionSave_as_Image->setIcon(icon2);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon3;
        iconThemeName = QString::fromUtf8("system-shutdown");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon3 = QIcon::fromTheme(iconThemeName);
        } else {
            icon3.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionQuit->setIcon(icon3);
        actionQuit->setMenuRole(QAction::QuitRole);
        actionAbout_Me = new QAction(MainWindow);
        actionAbout_Me->setObjectName(QString::fromUtf8("actionAbout_Me"));
        QIcon icon4;
        iconThemeName = QString::fromUtf8("mail-mark-important");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon4 = QIcon::fromTheme(iconThemeName);
        } else {
            icon4.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        actionAbout_Me->setIcon(icon4);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tools = new QTreeView(centralwidget);
        tools->setObjectName(QString::fromUtf8("tools"));
        tools->setGeometry(QRect(0, 0, 91, 551));
        toolCircle = new QPushButton(centralwidget);
        toolCircle->setObjectName(QString::fromUtf8("toolCircle"));
        toolCircle->setGeometry(QRect(50, 10, 31, 31));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("icons/ui/circle.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolCircle->setIcon(icon5);
        widget = new GLWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 0, 711, 551));
        widget->setCursor(QCursor(Qt::CrossCursor));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(10, 50, 31, 31));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("icons/ui/pen-fancy.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon6);
        toolPen = new QPushButton(centralwidget);
        toolPen->setObjectName(QString::fromUtf8("toolPen"));
        toolPen->setGeometry(QRect(10, 10, 31, 31));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("icons/ui/pen.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolPen->setIcon(icon7);
        toolSquare = new QPushButton(centralwidget);
        toolSquare->setObjectName(QString::fromUtf8("toolSquare"));
        toolSquare->setGeometry(QRect(50, 50, 31, 31));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("icons/ui/square.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolSquare->setIcon(icon8);
        colorBlue = new QPushButton(centralwidget);
        colorBlue->setObjectName(QString::fromUtf8("colorBlue"));
        colorBlue->setGeometry(QRect(10, 510, 31, 31));
        colorBlue->setStyleSheet(QString::fromUtf8("background:blue;"));
        colorPurple = new QPushButton(centralwidget);
        colorPurple->setObjectName(QString::fromUtf8("colorPurple"));
        colorPurple->setGeometry(QRect(50, 510, 31, 31));
        colorPurple->setStyleSheet(QString::fromUtf8("background: purple;"));
        colorRed = new QPushButton(centralwidget);
        colorRed->setObjectName(QString::fromUtf8("colorRed"));
        colorRed->setGeometry(QRect(50, 470, 31, 31));
        colorRed->setStyleSheet(QString::fromUtf8("background: red;"));
        colorGreen = new QPushButton(centralwidget);
        colorGreen->setObjectName(QString::fromUtf8("colorGreen"));
        colorGreen->setGeometry(QRect(10, 470, 31, 31));
        colorGreen->setStyleSheet(QString::fromUtf8("background: green;"));
        colorBlack = new QPushButton(centralwidget);
        colorBlack->setObjectName(QString::fromUtf8("colorBlack"));
        colorBlack->setGeometry(QRect(10, 430, 31, 31));
        colorBlack->setStyleSheet(QString::fromUtf8("background: black;"));
        colorWhite = new QPushButton(centralwidget);
        colorWhite->setObjectName(QString::fromUtf8("colorWhite"));
        colorWhite->setGeometry(QRect(50, 430, 31, 31));
        colorWhite->setStyleSheet(QString::fromUtf8("background: white;"));
        fontSize = new QSpinBox(centralwidget);
        fontSize->setObjectName(QString::fromUtf8("fontSize"));
        fontSize->setGeometry(QRect(41, 399, 41, 26));
        fontSize->setValue(5);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 390, 31, 41));
        toolLine = new QPushButton(centralwidget);
        toolLine->setObjectName(QString::fromUtf8("toolLine"));
        toolLine->setGeometry(QRect(50, 90, 31, 31));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("icons/ui/slash-forward.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolLine->setIcon(icon9);
        toolEraser = new QPushButton(centralwidget);
        toolEraser->setObjectName(QString::fromUtf8("toolEraser"));
        toolEraser->setGeometry(QRect(10, 130, 31, 31));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("icons/ui/eraser.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolEraser->setIcon(icon10);
        toolText = new QPushButton(centralwidget);
        toolText->setObjectName(QString::fromUtf8("toolText"));
        toolText->setGeometry(QRect(50, 130, 31, 31));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("icons/ui/text.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolText->setIcon(icon11);
        toolSpray = new QPushButton(centralwidget);
        toolSpray->setObjectName(QString::fromUtf8("toolSpray"));
        toolSpray->setGeometry(QRect(10, 90, 31, 31));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8("icons/ui/spray-can.svg"), QSize(), QIcon::Normal, QIcon::Off);
        toolSpray->setIcon(icon12);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 30));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addSeparator();
        menuFile->addAction(actionSave_as_Image);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout_Me);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Painty", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        actionSave_as_Image->setText(QCoreApplication::translate("MainWindow", "Save as Image", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionAbout_Me->setText(QCoreApplication::translate("MainWindow", "About Painty", nullptr));
        toolCircle->setText(QString());
        pushButton_7->setText(QString());
        toolPen->setText(QString());
        toolSquare->setText(QString());
        colorBlue->setText(QString());
        colorPurple->setText(QString());
        colorRed->setText(QString());
        colorGreen->setText(QString());
        colorBlack->setText(QString());
        colorWhite->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        toolLine->setText(QString());
        toolEraser->setText(QString());
        toolText->setText(QString());
        toolSpray->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

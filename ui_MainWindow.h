/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QSpinBox *width;
    QSpinBox *height;
    QSpinBox *cellSize;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *startGame;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 389);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        width = new QSpinBox(centralwidget);
        width->setObjectName(QString::fromUtf8("width"));
        width->setGeometry(QRect(70, 150, 61, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Roboto Bk"));
        font.setPointSize(12);
        width->setFont(font);
        width->setValue(60);
        height = new QSpinBox(centralwidget);
        height->setObjectName(QString::fromUtf8("height"));
        height->setGeometry(QRect(210, 150, 61, 41));
        height->setFont(font);
        height->setMaximum(100);
        height->setValue(50);
        cellSize = new QSpinBox(centralwidget);
        cellSize->setObjectName(QString::fromUtf8("cellSize"));
        cellSize->setGeometry(QRect(350, 150, 61, 41));
        cellSize->setFont(font);
        cellSize->setMaximum(50);
        cellSize->setValue(15);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 130, 61, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 130, 61, 21));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(340, 130, 81, 21));
        startGame = new QPushButton(centralwidget);
        startGame->setObjectName(QString::fromUtf8("startGame"));
        startGame->setGeometry(QRect(90, 220, 291, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Old English Text MT"));
        font1.setPointSize(48);
        startGame->setFont(font1);
        startGame->setCursor(QCursor(Qt::OpenHandCursor));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MistaSnake", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\273\320\265\321\202\320\272\320\270", nullptr));
        startGame->setText(QApplication::translate("MainWindow", "RUN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

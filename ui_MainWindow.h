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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QPushButton *startGame;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSpinBox *width;
    QSpinBox *height;
    QSpinBox *cellSize;
    QSpinBox *foodCount;
    QSpinBox *gameSpeed;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLineEdit *ipEdit;
    QPushButton *connectButton;
    QLineEdit *playerEdit;
    QPushButton *createButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 389);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setAutoFillBackground(false);
        startGame = new QPushButton(centralwidget);
        startGame->setObjectName(QString::fromUtf8("startGame"));
        startGame->setGeometry(QRect(100, 220, 291, 111));
        QFont font;
        font.setFamily(QString::fromUtf8("Old English Text MT"));
        font.setPointSize(48);
        startGame->setFont(font);
        startGame->setCursor(QCursor(Qt::OpenHandCursor));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 140, 451, 61));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 3, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 0, 4, 1, 1);

        width = new QSpinBox(layoutWidget);
        width->setObjectName(QString::fromUtf8("width"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Roboto Bk"));
        font1.setPointSize(12);
        width->setFont(font1);
        width->setValue(60);

        gridLayout->addWidget(width, 1, 0, 1, 1);

        height = new QSpinBox(layoutWidget);
        height->setObjectName(QString::fromUtf8("height"));
        height->setFont(font1);
        height->setMaximum(100);
        height->setValue(50);

        gridLayout->addWidget(height, 1, 1, 1, 1);

        cellSize = new QSpinBox(layoutWidget);
        cellSize->setObjectName(QString::fromUtf8("cellSize"));
        cellSize->setFont(font1);
        cellSize->setMaximum(50);
        cellSize->setValue(15);

        gridLayout->addWidget(cellSize, 1, 2, 1, 1);

        foodCount = new QSpinBox(layoutWidget);
        foodCount->setObjectName(QString::fromUtf8("foodCount"));
        foodCount->setFont(font1);
        foodCount->setMinimum(1);
        foodCount->setMaximum(50);
        foodCount->setValue(25);

        gridLayout->addWidget(foodCount, 1, 3, 1, 1);

        gameSpeed = new QSpinBox(layoutWidget);
        gameSpeed->setObjectName(QString::fromUtf8("gameSpeed"));
        gameSpeed->setFont(font1);
        gameSpeed->setMinimum(1);
        gameSpeed->setMaximum(10);
        gameSpeed->setValue(5);

        gridLayout->addWidget(gameSpeed, 1, 4, 1, 1);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 0, 281, 81));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        ipEdit = new QLineEdit(layoutWidget1);
        ipEdit->setObjectName(QString::fromUtf8("ipEdit"));
        QFont font2;
        font2.setPointSize(16);
        ipEdit->setFont(font2);
        ipEdit->setAutoFillBackground(false);

        gridLayout_2->addWidget(ipEdit, 0, 0, 1, 1);

        connectButton = new QPushButton(layoutWidget1);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setEnabled(true);

        gridLayout_2->addWidget(connectButton, 0, 1, 1, 1);

        playerEdit = new QLineEdit(layoutWidget1);
        playerEdit->setObjectName(QString::fromUtf8("playerEdit"));
        playerEdit->setFont(font2);
        playerEdit->setAutoFillBackground(false);

        gridLayout_2->addWidget(playerEdit, 1, 0, 1, 1);

        createButton = new QPushButton(layoutWidget1);
        createButton->setObjectName(QString::fromUtf8("createButton"));

        gridLayout_2->addWidget(createButton, 1, 1, 1, 1);

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
        startGame->setText(QApplication::translate("MainWindow", "RUN", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\250\320\270\321\200\320\270\320\275\320\260", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\201\320\276\321\202\320\260", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\274\320\265\321\200 \320\272\320\273\320\265\321\202\320\272\320\270", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\265\320\264\321\213", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\270\320\263\321\200\321\213", nullptr));
#ifndef QT_NO_TOOLTIP
        ipEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        ipEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        ipEdit->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        ipEdit->setText(QString());
        ipEdit->setPlaceholderText(QApplication::translate("MainWindow", "ip address", nullptr));
        connectButton->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
#ifndef QT_NO_TOOLTIP
        playerEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        playerEdit->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_ACCESSIBILITY
        playerEdit->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        playerEdit->setText(QApplication::translate("MainWindow", "USUAL SNAKE", nullptr));
        playerEdit->setPlaceholderText(QApplication::translate("MainWindow", "name", nullptr));
        createButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\201\320\265\321\200\320\262\320\265\321\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

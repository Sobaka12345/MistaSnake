#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QStringListModel>
#include <QHostInfo>
#include <QString>
#include <QNetworkInterface>

#include <iostream>
#include <thread>
#include <mutex>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Field.h"
#include "ServerListForm.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void runGame(unsigned int width, unsigned int height, unsigned int cellSize,
                 unsigned int foodCount, unsigned int gameSpeed);

    void setButtonEnabled();

private slots:

    void on_startGame_clicked    ();

    void on_connectButton_clicked();

    void on_createButton_clicked ();

private:
    Ui::MainWindow *ui;
    sf::TcpSocket server;
    sf::RenderWindow window;
    QStringListModel servers;
    ServerListForm serverBox;

    bool parentClose;

    void closeEvent(QCloseEvent * event);
};

#endif // MAINWINDOW_H

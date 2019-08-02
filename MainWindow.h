#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Field.h"

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
    void runGame(unsigned int width, unsigned int height, unsigned int cellSize);

private slots:

    void on_startGame_clicked();

private:
    Ui::MainWindow *ui;
    sf::RenderWindow window;
    bool parentClose;

    void closeEvent(QCloseEvent * event);
};

#endif // MAINWINDOW_H

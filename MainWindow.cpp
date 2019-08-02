#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runGame(unsigned int width, unsigned int height, unsigned int cellSize)
{

    Field * field = Field::createField(width, height, cellSize);

    window.create(sf::VideoMode(width * cellSize, height * cellSize),
                            "MistaSnake", sf::Style::Titlebar | sf::Style::Close);

    parentClose = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || parentClose)
            {
                window.close();
                QPushButton * el = this->findChild<QPushButton *>("startGame");
                el->setEnabled(true);
            }
        }
        window.clear();
        for (auto x: field->onDraw())
            window.draw(x);
        window.display();
    }

    delete field;
}

void MainWindow::on_startGame_clicked()
{
    QPushButton * bt = this->findChild<QPushButton *>("startGame");
    bt->setEnabled(false);
    QSpinBox * el = this->findChild<QSpinBox *>("height");
    unsigned int height = el->text().toUInt();
    el = this->findChild<QSpinBox *>("width");
    unsigned int width = el->text().toUInt();
    el = this->findChild<QSpinBox *>("cellSize");
    unsigned int cellSize = el->text().toUInt();

    runGame(width, height, cellSize);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    parentClose = true;
}

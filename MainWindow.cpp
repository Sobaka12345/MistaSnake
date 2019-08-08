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

    sf::Clock clock;
    sf::Time elapsed_1;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        elapsed_1 += elapsed;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || parentClose)
            {
                window.close();
                ui->startGame->setEnabled(true);
            }
        }
        window.clear();
        for (auto x: field->onDraw())
            window.draw(x);
        if(elapsed_1.asSeconds() > 0.1)
        {
            field->update(1);
            elapsed_1 = elapsed_1.Zero;
        }
        window.display();
    }

    delete field;
}

void MainWindow::on_startGame_clicked()
{
    ui->startGame->setEnabled(false);
    unsigned int height = ui->height->text().toUInt();
    unsigned int width = ui->width->text().toUInt();
    unsigned int cellSize = ui->cellSize->text().toUInt();

    runGame(width, height, cellSize);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    parentClose = true;
}

#include "MainWindow.h"
#include "ui_MainWindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    serverBox(this)
{
    ui->setupUi(this);
    serverBox.setHostName(ui->playerEdit->text());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runGame(unsigned int width, unsigned int height, unsigned int cellSize,
                         unsigned int foodCount, unsigned int gameSpeed)
{

    Field * field = Field::createField(width, height, cellSize, foodCount);

    window.create(sf::VideoMode(width * cellSize, height * cellSize),
                            "MistaSnake", sf::Style::Titlebar | sf::Style::Close);

    parentClose = false;

    sf::Clock clock;
    sf::Time elapsed;
    while (window.isOpen())
    {
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

        field->update(elapsed.asSeconds());
        elapsed = clock.restart();
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
    unsigned int foodCount = ui->foodCount->text().toUInt();
    unsigned int gameSpeed = ui->gameSpeed->text().toUInt();

    runGame(width, height, cellSize, foodCount, gameSpeed);
}


void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    parentClose = true;
}


void MainWindow::on_connectButton_clicked()
{
   ui->connectButton->setEnabled(false);
   serverBox.show();
   serverBox.connectToServer(ui->ipEdit->text(), ui->playerEdit->text());
}



void MainWindow::on_createButton_clicked()
{
    ui->connectButton->setEnabled(false);
    serverBox.show();
    serverBox.listenClients();
}

void MainWindow::setButtonEnabled()
{
    ui->connectButton->setEnabled(true);
}

QString MainWindow::getName()
{
    QString a(ui->playerEdit->text());
    return a;
}

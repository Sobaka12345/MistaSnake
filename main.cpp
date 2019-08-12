#include <QApplication>


#include "MainWindow.h"


int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    MainWindow mainMenu;

    mainMenu.show();
    //slf.show();

    return app.exec();
}

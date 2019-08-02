#include <QApplication>


#include "MainWindow.h"


int main(int argc, char ** argv)
{
    QApplication app(argc, argv);
    MainWindow mainMenu;
    mainMenu.show();
    return app.exec();


}

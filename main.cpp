#include "square.h"
#include "squareColor.h"
#include "board.h"
#include "game.h"
#include "mainwindow.h"
#include <QApplication>
#include "fileReader.h"

using namespace std;

/**
 * @brief startGraphic launches the graphic version of the game
 * @param argc the first parameter
 * @param argv the second parameter
 * @return if it has launches or not.
 */
int startGraphic(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


/**
 * @brief main is the main of the application
 * @param argc the first parameter
 * @param argv the second parameter
 * @return if it ended or not
 */
int main(int argc, char *argv[])
{
    startGraphic(argc,argv);
}


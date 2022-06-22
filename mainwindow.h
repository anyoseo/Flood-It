#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

namespace Ui {
class MainWindow;
}


/**
 * @brief The MainWindow class represents the main window of the game.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief MainWindow is the constructor of the class MainWinw.
     * @param parent is the QWidget parent.
     */
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    /**
     * @brief on_pushButton_clicked starts the game when the play button is clicked.
     */
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    gameWindow *gameWindow;
};

#endif // MAINWINDOW_H

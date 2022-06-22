#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include "Observer.h"
#include "game.h"
#include "clickablelabel.h"
#include <QDialog>

namespace Ui {
class gameWindow;
}

/**
 * @brief The gameWindow class represents the game application at the graphical level.
 */
class gameWindow : public QDialog,public Observer
{
    Q_OBJECT

public:

    /**
     * @brief gameWindow is the constructor of the class gameWindow.
     * @param parent is the parent of the class.
     * @param row is the number of rows of the board .
     * @param column is the number of columns of the board.
     * @param nbColor is the number of colors of the board.
     */
    explicit gameWindow(QWidget *parent = nullptr,unsigned row=0,unsigned column=0,unsigned nbColor=0);
    ~gameWindow() override;

private:
    Ui::gameWindow* ui;
    Game game;
    std::vector<std::vector<ClickableLabel*>> board;

    /**
     * @brief initializeBoard initialize the attribute board of the class gameWindow.
     */
    void initializeBoard();

    /**
     * @brief isWin checks if the game is over or not.
     */
    void isWin();

    /**
     * @brief labelMoves displays the number of moves done by the player.
     */
    void labelMoves();

    /**
     * @brief labelOldScore displays the current highest score for this game board.
     */
    void labelOldScore();

    /**
     * @brief update is updtating the gameWindow display.
     */
    void update() override;

    /**
     * @brief setGameBoard set the board display of the class gameWindow.
     * @param row the nummber of rows of the board of the game.
     * @param column the number of columns of the board of the game.
     */
    void setGameBoard(unsigned row,unsigned column);
};

#endif // GAMEWINDOW_H

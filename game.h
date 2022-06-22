#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "Observable.h"
#include "square.h"
#include "fileReader.h"

/**
 * @brief The Game class represents the game's functions of application.
 */
class Game : public Observable
{

private:
    Board board;
    unsigned counter;
    unsigned row;
    unsigned column;
    unsigned nbColor;
    SquareColor newColor;
    FileReader fileReader;
public:

    /**
     * @brief Game is the default constructor of the class game.
     */
    Game();

    /**
     * @brief Game is the constructor with parameters of the class game.
     * @param row is the number of rows of the board for the game.
     * @param column is the number of columns of the board for the game.
     * @param nbColor is the color of the board for the game.
     */
    Game(unsigned row,unsigned column,unsigned nbColor);

    /**
     * @brief isOver chekc if the game is over.
     * @return true if it's over else false.
     */
    bool isOver();

    /**
     * @brief changeColor changes the color of the game's board.
     */
    void changeColor();

    /**
     * @brief operator =
     * @param game_
     * @return
     */
    Game& operator=(Game game_);

    /**
     * @brief getCounter gets the attribute counter of the game.
     * @return the counter of moves of the game.
     */
    inline unsigned getCounter();

    /**
     * @brief getSquareColor gets the color of the square.
     * @param row is the row position of the square.
     * @param column is the column position of the square.
     * @return the color of the square asked.
     */
    inline SquareColor getSquareColor(unsigned row,unsigned column);

    /**
     * @brief newColorSelected selects the new color.
     * @param row the row of the new color selected.
     * @param column the column of the new color selected.
     */
    inline void newColorSelected(unsigned row,unsigned column);

    /**
     * @brief getSquare gets the square at the given position.
     * @param row is the row of the square asked.
     * @param column is the column of the square asked.
     * @return the square of the board which was asked.
     */
    inline Square getSquare(unsigned row,unsigned column);

    /**
     * @brief writeFile writes in the file the new score.
     */
    inline void writeFile();

    /**
     * @brief newHighScore checks if the player has beaten the previous score.
     * @return true if he beat it else false.
     */
    inline bool newHighScore();

    /**
     * @brief oldHighScore gets the current highest score of the current game board.
     * @return the current highest score.
     */
    inline unsigned oldHighScore();
};
unsigned Game::getCounter(){
    return counter;
}

SquareColor Game::getSquareColor(unsigned row,unsigned column){
    return board.getSquare(row,column).getColor();
}


void Game::newColorSelected(unsigned int row, unsigned int column){
    newColor=getSquareColor(row,column);
}

Square Game::getSquare(unsigned row,unsigned column){
    return board.getBoard().at(row).at(column);
}

void Game::writeFile(){
    fileReader.writeFile(row,column,nbColor,counter);
}

bool Game::newHighScore(){
    if(fileReader.highScore(row,column,nbColor)==0){
        return true;
    }else{
        return counter<fileReader.highScore(row,column,nbColor);
    }
}

unsigned Game::oldHighScore(){
    return fileReader.highScore(row,column,nbColor);
}

#endif // GAME_H

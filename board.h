#ifndef BOARD_H
#define BOARD_H

#include "square.h"
#include <vector>

/**
 * @brief The Board class represents the board of the game.
 */

class Board
{

private:

    std::vector<std::vector<Square>> board;
    int row;
    int column;

public:

    /**
     * @brief Board is the default constructor of the class Board.
     */
    Board();

    /**
     * @brief Board is the constructor with parameters of the class Board.
     * @param row represents the number of rows of the board.
     * @param column represents the number of columns of the board.
     * @param nbColor represents the number of colors of the board's game.
     */
    Board(int row,int column,unsigned nbColor);

    /**
     * @brief floodUtil changes the color the board.
     * @param x is the value of the row.
     * @param y is the value of the column.
     * @param prevC is the previous color to be changed.
     * @param newC is the new color to be placed.
     */
    void floodUtil(int x ,int y, SquareColor prevC,SquareColor newC);

    /**
     * @brief floodFill is the interface of the recursive function which changes the color of the board.
     * @param x is the value of the row.
     * @param y is the value of the columns.
     * @param newC is the new color to be placed.
     */
    void floodFill(int x, int y, SquareColor newC);

    /**
     * @brief getBoard gets the attribute board of the class.
     * @return a vector of Square which represents the board.
     */
    inline std::vector<std::vector<Square>>& getBoard();

    /**
     * @brief getSquare gets the square asked from the board.
     * @param row is the value of the square row position.
     * @param column is the value of the square column position.
     * @return a Square from the game's board.
     */
    inline Square getSquare(int row,int column);
};

std::vector<std::vector<Square>>& Board::getBoard(){
    return board;
}

Square Board::getSquare(int row, int column){
    return board.at(row).at(column);
}
#endif // BOARD_H

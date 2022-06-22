#ifndef SQUARE_H
#define SQUARE_H
#include "squareColor.h"
#include <QLabel>
#include <QWidget>
#include <Qt>


/**
 * @brief The Square class represents a square of the board from the game.
 */
class Square
{

private:
    SquareColor color;

public:

    /**
     * @brief Square is the default constructor of the class Square.
     */
    Square();

    /**
     * @brief Square is the constructor with a parameter of the class Square.
     * @param is the color of the square.
     */
    Square(SquareColor squareColor);

    /**
     * @brief getColor gets attribute color of the square.
     * @return the color of the square.
     */
    inline SquareColor getColor();

    /**
     * @brief setColor sets the attribute color to the new color given in parameter.
     * @param newC is the new color for the square.
     */
    inline void setColor(SquareColor newC);

};

SquareColor Square::getColor(){
    return color;
}
void Square::setColor(SquareColor color){
    this->color=color;
}

#endif // SQUARE_H

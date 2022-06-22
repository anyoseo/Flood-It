#include "square.h"
Square::Square(){
    color=SquareColor::RED;
}
Square::Square(SquareColor squareColor):color{squareColor}
{
}

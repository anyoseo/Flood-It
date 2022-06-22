#include "board.h"
#include <stdlib.h>

Board::Board(){

}

Board::Board(int row,int column,unsigned nbColor):row{row},column{column}
{
    std::vector<Square> v;
    for (int i = 0 ; i <= row ; i++){
        v.clear();
        for (int j = 0 ; j <=column ; j++){
            v.push_back(Square(static_cast<SquareColor>(rand()%nbColor)));
        }
        board.push_back(v);
    }

}
void Board::floodUtil(int x ,int y, SquareColor prevC,SquareColor newC){
    // Base cases
        if (x < 0 || x >= row || y < 0 || y >= column)
            return;
        if (board.at(x).at(y).getColor() != prevC)
            return;
        if (board.at(x).at(y).getColor() == newC)
            return;

        // Replace the color at (x, y)
        board.at(x).at(y).setColor(newC);

        // Recur for north, east, south and west
        floodUtil(x+1, y, prevC, newC);
        floodUtil(x-1, y, prevC, newC);
        floodUtil(x, y+1, prevC, newC);
        floodUtil(x, y-1, prevC, newC);
}


void Board::floodFill(int x, int y, SquareColor newC)
{
    SquareColor prevC = board.at(x).at(y).getColor();
    floodUtil(x, y, prevC, newC);
}



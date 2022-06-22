#include "game.h"

Game::Game(){
    counter=0;
    row=0;
    column=0;
    nbColor=0;
}
Game::Game(unsigned row,unsigned column,unsigned nbColor):counter{0},row{row},column{column},nbColor{nbColor}
{
    board=Board(row,column,nbColor);
}

bool Game::isOver(){
    SquareColor finalColor=getSquareColor(0,0);

    for(unsigned i=0;i<row;i++){
        for(unsigned j=0;j<column;j++){
                if(finalColor!=getSquareColor(i,j)){
                    return false;
                }
        }
    }
    return true;
}

void Game::changeColor(){
    if(board.getSquare(0,0).getColor()!=newColor){
        counter++;
    }
    board.floodFill(0,0,newColor);
    notify();
}

Game& Game::operator=(Game game_){
    board=game_.board;
    counter=game_.counter;
    row=game_.row;
    column=game_.column;
    nbColor=game_.nbColor;
    newColor=game_.newColor;

    return *this;
}


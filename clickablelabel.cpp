#include "clickablelabel.h"


ClickableLabel::ClickableLabel(unsigned row,unsigned column,QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {
    row_=row;
    column_=column;
    game=nullptr;

}

ClickableLabel::~ClickableLabel() {
    delete game;
}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    emit clicked();
    game->newColorSelected(row_,column_);
    game->changeColor();
}

void ClickableLabel::bgColor(){

    if(this->square.getColor()==SquareColor::RED){
        this->setStyleSheet("QLabel { background-color: red }");
    }else if(this->square.getColor()==SquareColor::BLUE){
        this->setStyleSheet("QLabel { background-color: blue }");
    }else if(this->square.getColor()==SquareColor::GREEN){
        this->setStyleSheet("QLabel { background-color: green }");
    }else if(this->square.getColor()==SquareColor::WHITE){
        this->setStyleSheet("QLabel { background-color: white }");
    }else if(this->square.getColor()==SquareColor::YELLOW){
        this->setStyleSheet("QLabel { background-color: yellow }");
    }

}

void ClickableLabel::updateColor(){

    if(this->game->getSquare(row_,column_).getColor()==SquareColor::RED){
        this->setStyleSheet("QLabel { background-color: red }");
    }else if(this->game->getSquare(row_,column_).getColor()==SquareColor::BLUE){
        this->setStyleSheet("QLabel { background-color: blue }");
    }else if(game->getSquare(row_,column_).getColor()==SquareColor::GREEN){
        this->setStyleSheet("QLabel { background-color: green }");
    }else if(this->game->getSquare(row_,column_).getColor()==SquareColor::WHITE){
        this->setStyleSheet("QLabel { background-color: white }");
    }else if(game->getSquare(row_,column_).getColor()==SquareColor::YELLOW){
        this->setStyleSheet("QLabel { background-color: yellow }");
    }

}
void ClickableLabel::setSquare(){
    square=game->getSquare(row_,column_);
    bgColor();
}

void ClickableLabel::update(){
    updateColor();
}

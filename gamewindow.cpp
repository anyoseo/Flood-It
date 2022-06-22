#include "gamewindow.h"
#include "ui_gamewindow.h"
#include <QMessageBox>
#include <QGridLayout>

gameWindow::gameWindow(QWidget *parent,unsigned row,unsigned column,unsigned nbColor) :
    QDialog(parent),
    ui(new Ui::gameWindow),game(Game(row,column,nbColor))
{
    ui->setupUi(this);
    labelMoves();
    labelOldScore();
    setGameBoard(row,column);
    initializeBoard();
    game.addObs(*this);
}
void gameWindow::initializeBoard(){
    for (unsigned i=0;i<this->board.size();i++) {
        for (unsigned j=0;j<this->board.at(i).size();j++) {
            this->board[i][j]->setGame(game);
        }
    }
}

void gameWindow::setGameBoard(unsigned row,unsigned column){
    std::vector<ClickableLabel*> v;
    for (unsigned i=0;i<row;i++) {
        v.clear();
        for (unsigned j=0;j<column;j++) {
            ClickableLabel * label=new ClickableLabel(i,j);
            ui->gridLayout->addWidget(label,i,j);
            v.push_back(label);
        }
        board.push_back(v);
    }

}
void gameWindow::labelMoves(){
        ui->counter->setText(QString::number(game.getCounter()));
        ui->counter->setStyleSheet("QLabel { color : white; }");
}

void gameWindow::labelOldScore(){
    ui->oldReord->setText(QString::number(game.oldHighScore()));
    ui->oldReord->setStyleSheet("QLabel { color : white; }");
}

gameWindow::~gameWindow()
{
    for (auto p : board)
      {
        for(auto label:p){
            delete label;
        }
        p.clear();
      }
      board.clear();
    delete ui;
}
void gameWindow::isWin(){
         if(game.newHighScore()){
             QString counter=QString("VOUS AVEZ GAGNE EN %1 COUPS ET BATTU LE RECORD QUI ETAIT : %2").arg(game.getCounter()).arg(game.oldHighScore());
             game.writeFile();
             QMessageBox qmsg=QMessageBox();
             qmsg.information(nullptr,tr("VICTOIRE"),counter);
             qmsg.show();
         }else{
            QString counter=QString("VOUS AVEZ GAGNE EN %1 COUPS").arg(game.getCounter());
            QMessageBox qmsg=QMessageBox();
            qmsg.information(nullptr,tr("VICTOIRE"),counter);
            qmsg.show();
         }
}

void gameWindow::update(){
    labelMoves();
    if(game.isOver()){
        isWin();
    }
}

#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include "Observer.h"
#include "game.h"
#include <iostream>


/**
 * @brief The ClickableLabel class represents the square on the graphic part of the game.
 */
class ClickableLabel : public QLabel,public Observer {
    Q_OBJECT

private :
    unsigned row_;
    unsigned column_;
    Game* game;
    Square square;

public:

    /**
     * @brief ClickableLabel is the constructor of the class ClickableLabel.
     * @param row is the number of rows for the game's board.
     * @param column is the number of columns for the game's board.
     * @param parent is the parent of the class.
     * @param f os the flag of the class.
     */
    explicit ClickableLabel(unsigned row=0,unsigned column=0,QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();

    /**
     * @brief bgColor displays the color of the square on the label.
     */
    void bgColor();

    /**
     * @brief setSquare sets the attribute square and displays the color.
     */
    void setSquare();

    /**
     * @brief updateColor updates the display of the color of the square.
     */
    void updateColor();

    /**
     * @brief update lets updating the displays.
     */
    void update();

    /**
     * @brief setGame sets the attribute game.
     * @param game the value to initializes the attribute game.
     */
    inline void setGame(Game &game);

    /**
     * @brief setRowColumn sets the row and column of the label.
     * @param row is the row of the label.
     * @param column is the column of the label.
     */
    inline void setRowColumn(unsigned row,unsigned column);

signals:

    /**
     * @brief clicked sets the action of clicking.
     */
    void clicked();

protected:

    /**
     * @brief mousePressEvent executes the task when the label is being clicked on.
     * @param event the event of clicking.
     */
    void mousePressEvent(QMouseEvent* event);

};

void ClickableLabel::setGame(Game &game_){
    game= &game_;
    game->addObs(*this);
    setSquare();
}

void ClickableLabel::setRowColumn(unsigned int row, unsigned int column){
    row_=row;
    column_=column;
}

#endif // CLICKABLELABEL_H

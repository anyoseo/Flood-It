#ifndef FILEREADER_H
#define FILEREADER_H


/**
 * @brief The FileReader class represents the file reader of the scores file for the game.
 */
class FileReader{

public:
    /**
     * @brief highScore gets the highest score for the current game board.
     * @param row the number of row of the board.
     * @param column the number of column of the board.
     * @param nbColor the number of colors of the board.
     * @return the highest score.
     */
    unsigned highScore(unsigned row,unsigned column, unsigned nbColor);

    /**
     * @brief writeFile writes in the file the new score.
     * @param row the number of row of the board.
     * @param column the number of column of the board.
     * @param nbColor the number of colors of the board.
     * @param newScore the new score for the current board.
     */
    void writeFile(unsigned row,unsigned column,unsigned nbColor,unsigned newScore);

    /**
     * @brief init initializes the scores file for the first time.
     */
    void init();
};



#endif // FILEREADER_H

/**
 * @file Board.h
 * @author Alejandro Rubio, Ximo Sanz
 * @brief The file which contains the TDA object Board
 */

#ifndef BOARD_H
#define BOARD_H

#include "piece.h"

/**
 * @class Board
 * @brief Represents the board in the game
 * 
 */
class Board {
private:
    short int** matrix;
    int rows, columns;

    /**
     * @brief Allocates memory for the matrix
     * 
     * @param r Rows to allocate
     * @param c Columns to allocate
     * @pre @p r and @p c are both greater than 0
     */
    void allocate(int r, int c);
    /**
     * @brief Desallocate the matrix memory in usage
     * 
     */
    void deallocate();
    /**
     * @brief Copy an object in another one
     * 
     * @param t The object we want to copy
     */
    void copy(const Board &t);

public:
    /**
     * @brief Construct a new Board object
     * 
     */
    Board();
    /**
     * @brief Construct a new Board object from parameters
     * 
     * @param r The rows
     * @param c The columns
     * @pre @p r and @p c are both greater than 0
     */
    Board(int r, int c);
    /**
     * @brief Copy constructor of a new object T
     * 
     * @param t The Board we want to copy
     */
    Board(const Board &t);
    /**
     * @brief Destroy the Board object
     * 
     */
    ~Board();
    /**
     * @brief Return a value in matrix at the given position
     * 
     * @param r The row where the value is
     * @param c The column where the value is
     * @pre @p r and @p c must be in the right values
     * @return int The value
     */
    int get(int r, int c) const;
    /**
     * @brief Return the number of rows 
     *  
     * @return int The number of rows
     */
    int getRows() const;
    /**
     * @brief Return the number of columns 
     *  
     * @return int The number of columns
     */
    int getColumns() const;
    /**
     * @brief Set the value of a given position
     * 
     * @param r The row where the value is
     * @param c The column where the value is
     * @param v The value we want to introduce between 1 and 7
     * @pre @p r and @p c must be in the right values
     */
    void set(int r, int c, int v);
    /**
     * @brief Introudce a piece onto the top of the matrix
     * 
     * @param p The piece we want to introduce
     */
    void add(const Piece &p);
    /**
     * @brief Function that clears a row and moves the upper rows one position below
     *        and the top becomes empty
     * 
     * @param r The row to clear
     */
    void clearRow(int r);
    /**
     * @brief Check if the given row is full
     * 
     * @param r The row we want to check
     * @return true if the row is full
     * @return false if the row has any empty positions
     */
    bool fullRow(int r) const;
    /**
     * @brief Check if a given piece can continue falling
     * 
     * @param p The piece to check
     * @return true If the piece can continue falling
     * @return false if not
     */
    bool canFall(const Piece &p) const;
    /**
     * @brief Check if a piece can move into a given direction
     * 
     * @param p The piece we want to move
     * @param direction True to the right, false to the left
     * @return true If the piece can move
     * @return false If the piece can not move
     */
    bool canMove(const Piece &p, bool direction) const;
    /**
     * @brief Check if a piece can turn into a given direction
     * 
     * @param p The piece we wanto to turn
     * @param direction True to right, false to left
     * @return true If it can be turned
     * @return false If it can not be turned
     */
    bool canTurn(const Piece &p, bool direction) const;
    /**
     * @brief Fix a piece in the board when cant continue moving
     * 
     * @param p The piece to fix
     */
    void fix(const Piece &p);
    /**
     * @brief Check if the next piece is out of the board on the top
     * 
     * @return true If the next piece can be introduced
     * @return false If not
     */
    bool finish();
    /**
     * @brief Overload the = operator
     * 
     * @param b The board we want to =
     * @return Board The new board
     */
    Board& operator=(const Board &b);
    /**
     * @brief Overload the [] operator for vectors of vectors
     * 
     * @param i The position we want to return
     * @return short int The first position of the vector
     */
    short int &operator[](int i);
    
};

/**
 * @brief Overload the >> operator 
 * 
 * @param stream The stream of datas
 * @param b The board where we will introduce the data
 * @return std::istream& The stream
 */
std::istream& operator>>(std::istream& stream, Board &b);
/**
 * @brief Overload the << operator 
 * 
 * @param stream The stream of datas
 * @param b The board from which we will show the datas
 * @return std::ostream& The stream
 */
std::ostream& operator<<(std::ostream& stream, const Board &b);

#endif
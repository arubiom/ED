/**
 * @file piece.h
 * @author Alejandro Rubio, Ximo Sanz
 * @brief The file which contains the TDA object Piece
 * 
 */
#ifndef PIECE_H
#define PIECE_H

#include <iostream>
#include <fstream>

#define RED = 1
#define GREEN = 2
#define BLUE = 3
#define ORANGE = 4
#define PURPLE = 5
#define YELLOW = 6
#define CYAN = 7

/**
 * @brief The class Piece
 * 
 */
class Piece {
private:
    short int** matrix;
    int nRows, nCols;
    int posx, posy;

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
     * @param p The object we want to copy
     */
    void copy(const Piece &p);

public:
    /**
     * @brief Construct a new Piece object depending of n
     * 
     * @param n If n is 0 it builds a random piece, otherwise build the known piece
     * @pre @p n must be between the values of 0-7
     */
    Piece(int n = 0);
    /**
     * @brief Construct a new Piece object from a given Piece
     * 
     * @param p The piece
     */
    Piece(Piece p);
    
    /**
     * @brief Destroy the Piece object
     * 
     */
    ~Piece();
    /**
     * @brief Get the posx of the object
     * 
     * @return int posx
     */
    int getPosx() const;
    /**
     * @brief Get the posy of the object
     * 
     * @return int posy
     */
    int getPosy() const;
    /**
     * @brief Get the number of rows of the object
     * 
     * @return int nRows
     */
    int getRow() const;
    /**
     * @brief Get the number of columns of the object
     * 
     * @return int nCols
     */
    int getCol() const;
    /**
     * @brief Gets the color, (represented by a number), of the matrix
     * 
     * @return int The element in the @p r, @p c position
     */
    short int get(int r, int c) const;
    /**
     * @brief Set the Posx of the object
     * @pre @p x must be a possible position
     * 
     * @param x The position in the abcissa axis
     * 
     */
    void setPosx(int x);
    /**
     * @brief Set the Posy object
     * 
     * @param y The position in the y-axis diagram 
     */
    void setPosy(int y);
    /**
     * @brief Set the number of rows of the matrix
     * 
     * @param r The number of rows
     * @pre @p r must be a valid number
     */
    void setnRows(int r);
    /**
     * @brief Set the number of columns of the matrix
     * 
     * @param c The columns
     * @pre @p c must be a valid number
     */
    void setnCols(int c);
    /**
     * @brief Set the number contained inside the number
     * 
     * @param color The number of the color
     * @param r The row we want to introduce the number
     * @param c The column where we want to introduce the number
     * @pre @p color must be between 1-7, @p c and @p r must be valids
     */
    void set(int color, int r , int c);
    /**
     * @brief Turns the piece to the right
     * 
     */
    void turnRight();
    /**
     * @brief Turns the piece to the left
     * 
     */
    void turnLeft();
    /**
     * @brief Move the piece to the right
     * 
     */
    void moveRight();
    /**
     * @brief Move the piece to the left
     * 
     */
    void moveLeft();
    /**
     * @brief Move the piece down
     * 
     */
    void moveDown();
    /**
     * @brief Move the piece up
     * 
     */
    void moveUp();
    /**
     * @brief Overload the = operator
     * 
     * @param p The piece we want to =
     * @return Piece The new piece
     */
    Piece& operator=(const Piece &p);
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
 * @param p The piece where we will introduce the data
 * @return std::istream& The stream
 */
std::istream& operator>>(std::istream& stream, Piece &p);
/**
 * @brief Overload the << operator 
 * 
 * @param stream The stream of datas
 * @param p The piece from which we will show the datas
 * @return std::ostream& The stream
 */
std::ostream& operator<<(std::ostream& stream, const Piece &p);

#endif 
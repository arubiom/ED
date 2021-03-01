/**
 * @file Piecelist.h
 * @author Alejandro Rubio, Ximo Sanz
 * @brief The file which contains the TDA object Piecelist, a vector of pieces
 */

#ifndef PIECELIST_H
#define PIECELIST_H

#include "piece.h"

#define MAX_PIECES = 4

/**
 * @brief The Piecelist class
 * 
 */
class Piecelist {
private:
    Piece* currentPieces;
    int nPieces;            //Must be always between 0 and MAX_PIECES

    /**
     * @brief Allocates memory for the matrix
     * 
     * @param n Rows to allocate
     * @pre @p n is greater than 0
     */
    void allocate(int n);
    /**
     * @brief Desallocate the vector memory in usage
     * 
     */
    void deallocate();
    /**
     * @brief Copy an object in another one
     * 
     * @param pl The object we want to copy
     */
    void copy(const Piecelist &pl);
    /**
     * @brief Fill the list with pieces
     * 
     * @param n The number of pieces we want to fill
     * @pre nPieces + @p n must be less or equal to MAX_PIECES
     */
    void fill(int n);
public:
    /**
     * @brief Construct a new Piecelist object
     * 
     * @param n The number of pieces in the list, by default MAX_PIECES
     */
    Piecelist(int n = MAX_PIECES);
    /**
     * @brief Copy constructor of the class 
     * 
     * @param pl The object we want to copy
     */
    Piecelist(const Piecelist &pl);
    /**
     * @brief Destroy the Piecelist object
     * 
     */
    ~Piecelist();
    /**
     * @brief Get the Size of the object
     * 
     * @return int nPieces
     */
    int getSize() const;
    /**
     * @brief Extract one piece from the list
     * 
     * @return Piece The extracted piece
     * @post After a piece has been extraxted is called fill(1);
     */
    Piece extract();
    /**
     * @brief Remove a piece from the beggining
     * 
     */
    void pop();
    /**
     * @brief Add a piece to the end of the list
     * 
     * @param p The piece we want to introduce
     * @pre nPieces must be < MAX_PIECES
     */
    void push(const Piece &p);
    /**
     * @brief Overload the += operator
     * 
     * @param p The piece we want to add
     * @return Piecelist& The piecelist with the piece added
     */
    Piecelist& operator+=(const Piece &p);
    /**
     * @brief Overload the [] operator for vectors of pieces
     * 
     * @param i The position we want to return
     * @return Piece The piece
     */
    Piece &operator[](int i);
};

/**
 * @brief Overload the >> operator 
 * 
 * @param stream The stream of datas
 * @param pl The stats where we will introduce the data
 * @return std::istream& The stream
 */
std::istream& operator>>(std::istream& stream, Piecelist &pl);
/**
 * @brief Overload the << operator 
 * 
 * @param stream The stream of datas
 * @param pl The stats from which we will show the datas
 * @return std::ostream& The stream
 */
std::ostream& operator<<(std::ostream& stream, const Piecelist &pl);
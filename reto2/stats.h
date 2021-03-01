/**
 * @file stats.h
 * @author Alejandro Rubio, Ximo Sanz
 * @brief The file which contains the TDA object Stats
 * 
 */
#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief The class Stats
 * 
 */
class Stats {
private:
    int time, destroyedRows, usedPieces, level;
    std::string title;

public:
    /**
     * @brief Construct a new Stats object
     * 
     */
    Stats();
    /**
     * @brief Construct a new Stats object with the specified title
     * 
     * @param a The title
     */
    Stats(std::string a);
    /**
     * @brief Get the Time of the object
     * 
     * @return int time
     */
    int getTime() const;
    /**
     * @brief Get the number of the destroyed rows object
     * 
     * @return int destroyedRows
     */
    int getRows() const;
    /**
     * @brief Get the number of  used Pieces of the object
     * 
     * @return int usedPieces
     */
    int getPieces() const;
    /**
     * @brief Get the Level object
     * 
     * @return int level
     */
    int getLevel() const;
    /**
     * @brief Get the Title of the object
     * 
     * @return std::string title
     */
    std::string getTitle() const;
    /**
     * @brief Set the Time of the object
     * 
     * @param n The time
     * @pre @p n must be positive
     */
    setTime(int n);
    /**
     * @brief Set the Rows object
     * 
     * @param r The destroyed rows
     * @pre r must be positive
     */
    setRows(int r);
    /**
     * @brief Set the Level object
     * 
     * @param l The new level
     * @pre @p l must be positive
     */
    setLevel(int l);
    /**
     * @brief Set the usedPieces of the object
     * 
     * @param p The number of used pieces
     * @pre @p p must be positive
     */
    setPieces(int p);
    /**
     * @brief Set the Title of the object
     * 
     * @param t The string which contains the title
     */
    setTitle(std::string t);
    /**
     * @brief Calculates the level of the game depending of the time
     * 
     */
    calculateLevel();


};

/**
 * @brief Overload the >> operator 
 * 
 * @param stream The stream of datas
 * @param s The stats where we will introduce the data
 * @return std::istream& The stream
 */
std::istream& operator>>(std::istream& stream, Stats &s);
/**
 * @brief Overload the << operator 
 * 
 * @param stream The stream of datas
 * @param s The stats from which we will show the datas
 * @return std::ostream& The stream
 */
std::ostream& operator<<(std::ostream& stream, const Stats &s);

#endif
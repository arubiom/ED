/**
 * @file game.h
 * @author Alejandro Rubio, Ximo Sanz
 * @brief The file which contains the TDA object Game
 * 
 */
#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piecelist.h"
#include "stats.h"
/**
 * @brief The Game class
 * 
 */
class Game {
private:
    Stats stat;
    Board board;
    Piecelist pieces;
    /**
     * @brief Copy an object in another one
     * 
     * @param g The object we want to copy
     */
    void copy(const Game &g);
public:
    /**
     * @brief Construct a new Game object
     * 
     */
    Game();
    /**
     * @brief Construct a new Game object from another one
     * 
     * @param match The game we want to copy
     */
    Game(const Game& match);
    /**
     * @brief Destroy the Game object
     * 
     */
    ~Game();
    /**
     * @brief Plays a determinated movement
     * 
     * @param movement The movement we want to do
     * @post If there is not a defined movement to that string it doesn't do anything
     */
    void play(std::string movement);
    /**
     * @brief Overload the = operator
     * 
     * @param g The game we want to =
     * @return Game The new game
     */
    Game& operator=(const Game &g);
};

/**
 * @brief Overload the >> operator 
 * 
 * @param stream The stream of datas
 * @param g The game where we will introduce the data
 * @return std::istream& The stream
 */
std::istream& operator>>(std::istream& stream, Game &g);
/**
 * @brief Overload the << operator 
 * 
 * @param stream The stream of datas
 * @param g The game from which we will show the datas
 * @return std::ostream& The stream
 */
std::ostream& operator<<(std::ostream& stream, const Game &g);

#endif
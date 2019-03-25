/* Samuel Bismuth 342533064 */

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"

// right: +1, left: -1.

enum class Sense { right, left };

class Game
{
private:
    //private members and functions
    void initialization();
    void nextTurn(Card newCurrent);
    void incrementTurn();
    std::vector<Player*> players;
    Card current;
    int turn;
    Sense sense;
    Game(const Game&); /* Copy constructor-private because we don't need it */
	Game operator=(const Game&); /* Operator-private because we don't need it */

public:
    //public members and functions
    Game(); //constructor
    void start();
    std::vector<Player*> getPlayers();
    Card& getCurrent();
    int& getTurn();
    Sense getSense();
    void setSence(Sense newSence);
};
#endif





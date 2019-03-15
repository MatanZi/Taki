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
    int operator ++(int);
    int operator --(int);
    vector<Player> players;
    Card current = Card::generate_card();
    int turn = 0;
    Sense sense = Sense::right;

public:
    //public members and functions
    void start();
    vector<Player> getPlayers();
    Card& getCurrent();
    int& getTurn();
    Sense getSense();
    void setSence(Sense newSence);
};
#endif





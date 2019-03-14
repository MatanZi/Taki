#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"

// right: +1, left: -1.

enum class Sense { right, left };
enum class Legal { legal, cardPb, notLegal};

class Game
{
private:
    //private members and functions
    void initialization();
    void makeRound();
    Legal isChoiceLegal(int choice);
    vector<Player> players;
    Card current = Card::generate_card();
    int turn = 0;
    Sense sense = Sense::right;

public:
    //public members and functions
    void start();
    vector<Player> getPlayers();
    Card getCurrent();
    int getTurn();
    Sense getSense();


};
#endif





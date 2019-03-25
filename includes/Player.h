/* Samuel Bismuth 342533064 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include<vector>
class Player
{
private:
    //private members
    std::string name;
    int nbCards;
    std::vector<Card> cards;
    bool makeChoice(Card& current);

public:
    //public members
    Player() : nbCards(1), name("") {}; /* default constructor */
    Player(std::string name, int nbCards, std::vector<Card> cards);
    bool play(Card&);
    std::string& getName();
    std::vector<Card>& getCards();
    int& getNbCards();
    friend std::ostream& operator << (std::ostream &os, Player&);
};
#endif




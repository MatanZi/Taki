/* Samuel Bismuth 342533064 */
/* Matan Zilka 307949438 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>

/*
   This is the class Player.
 */
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
Player() : nbCards(1), name("") {
};                                      /* default constructor */
Player(std::string name, int nbCards, std::vector<Card> cards);
bool play(Card&);
std::string& getName();
std::vector<Card>& getCards();
int& getNbCards();
friend std ::ostream& operator << (std::ostream &os, Player&);
};
#endif

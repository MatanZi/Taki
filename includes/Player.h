#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
class Player
{
private:
    //private members
	std::string name;
	int nbCards;
	vector<Card> cards;
	bool makeChoice(Card& current);

public:
    //public members
    Player(string name, int nbCards, vector<Card> cards);
	bool play(Card&);
	string getName();
	vector<Card> getCards();
	int getNbCards();
};
#endif




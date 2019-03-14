#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
class Player {
private:
	std::string name;
	int nbCards;
	vector<Card> cards;
	//private members

public:
    Player(string name, int nbCards, vector<Card> cards);
	//public members
	bool play(Card&);
	string getName();
	vector<Card> getCards();
	int getNbCards();
};
#endif




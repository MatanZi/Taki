#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
class Player {
private:
	std::string name;
	int num_of_cards;
	//vector of cards
	//private members

public:
	//public members
	bool play(Card&);
};
#endif




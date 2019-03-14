#include "../includes/Player.h"

Player::Player(string name, int nbCards, vector<Card> cards):name(name), nbCards(nbCards), cards(cards) {}

string Player::getName()
{
    return this->name;
}

int Player:: getNbCards()
{
    return this->nbCards;
}

vector<Card> Player::getCards()
{
    return this->cards;
}


/* Samuel Bismuth 342533064 */

#include "Player.h"

Player::Player(std::string name, int nbCards, std::vector<Card> cards):name(name), nbCards(nbCards), cards(cards) {}

bool Player::play(Card& current)
{
    std::cout << "current: " <<  current << std::endl;
    std::cout << this->getName() << ", your turn -" << std::endl;
    std::cout << "Your cards: ";
    std::cout << *this << std::endl;
    return this->makeChoice(current);
}

bool Player::makeChoice(Card& current)
{
    int choice;
    std::cin >> choice;
    if (choice < 1 || choice > this->getNbCards())
    {
        this->getCards().push_back(Card::generate_card());
        this->getNbCards()++;
        return false;
    }
    Card cardChoosed =  this->getCards()[choice - 1];
    if (cardChoosed.is_legal(current))
    {
        current = cardChoosed;
        this->getCards().erase(this->getCards().begin() + choice - 1);
        this->getNbCards()--;
        return true;
    }
    else
    {
        std::cout << "You can't put " << cardChoosed << " on " << current << std::endl;
        return this->makeChoice(current);
    }
}

/**
 * operator<<
 * return ostream& that contains all the list of cards.
 */
std::ostream& operator<< (std::ostream &os, Player& p)
{
    for(int i = 0; i < p.getNbCards(); i++)
    {
        std::cout << "(" << i + 1 << ")" << p.getCards()[i] << " ";
    }
    return os;
}

std::string& Player::getName()
{
    return this->name;
}

int& Player::getNbCards()
{
    return this->nbCards;
}

std::vector<Card>& Player::getCards()
{
    return this->cards;
}

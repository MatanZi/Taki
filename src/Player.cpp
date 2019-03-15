#include "../includes/Player.h"

Player::Player(string name, int nbCards, vector<Card> cards):name(name), nbCards(nbCards), cards(cards) {}

bool Player::play(Card& current)
{
    cout << "current: " <<  current << endl;
    cout << this->getName() << ", your turn -" << endl;
    cout << "Your cards: ";
    cout << "test" << this->getNbCards() << endl;
    for(int i = 0; i < this->getNbCards(); i++)
    {
        cout << "(" << i + 1 << ")" << this->getCards()[i] << " ";
    }
    cout << endl;
    return this->makeChoice(current);
}

bool Player::makeChoice(Card& current)
{
    int choice;
    cin >> choice;
    if (choice < 1 || choice > this->getNbCards()))
    {
        this->getCards().push_back(Card::generate_card());
        this->getNbCards()++;
        return false;
    }
    Card cardChoosed =  this->getCards()[choice - 1];
    if (cardChoosed.is_legal(current))
    {
        current = cardChoosed;
        //this->getCards().erase(this->getCards().begin() + choice - 1);
        this->getNbCards()--;
        return true;
    }
    else
    {
        cout << "you can't put " << cardChoosed << " on " << current << endl;
        return this->makeChoice(current);
    }
}

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


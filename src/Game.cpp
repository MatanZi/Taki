/* Samuel Bismuth 342533064 */

#include "Game.h"

/**
default constructor
*/
Game::Game()
{
    this->sense = Sense::right;
    this->turn = 0;
}

void Game::start()
{
    try
    {
        initialization();
    }
    catch (std::string error)
    {
        std::cout << "An exception occurred: " << error << '\n';
        exit(0);
    }
    this->current = Card::generate_card();
    while(true)
    {
        Player* currentPlayer;
        currentPlayer = this->getPlayers()[this->getTurn()];
        bool flag = currentPlayer->play(this->current);
        if (currentPlayer->getNbCards() == 0)
        {
            std::cout << currentPlayer->getName() << " wins!" << std::endl;
            return;
        }
        if (flag)
        {
            nextTurn(this->getCurrent());
        }
        else
        {
            this->incrementTurn();
        }
    }
}

/** \brief This function initialized the game.
 *
 * \param nbPlayers: Initially 0.
 * \param nbCards: Initially 0.
 * \return void function.
 *
 */
void Game::initialization()
{
    // TODO: Check if the input are authorized.
    std::cout << "How many players?" << std::endl;
    int nbPlayers;
    std::cin >>  nbPlayers;
    if (nbPlayers < 2)
    {
        throw std::string("You need two players at least!");
    }
    std::cout << "How many cards?" << std::endl;
    int nbCards;
    std::cin >>  nbCards;
    if (nbCards < 1)
    {
        throw std::string("You need one card at least!");
    }
    for (int i = 0; i < nbPlayers; i++)
    {
        std::cout << "player number " << i + 1 << " name?" << std::endl;
        std::string name;
        std::cin >>  name;
        std::vector<Card> cards;
        for (int j = 0; j < nbCards; j++)
        {
            cards.push_back(Card::generate_card());
        }
        // TODO: DESTRUCTOR.
        players.push_back(new Player(name, nbCards, cards));
    }
}

void Game::nextTurn(Card newCurrent)
{
    switch(newCurrent.get_sign())
    {
    case sign::PLUS:
        return;
    case sign::CD:
        switch(this->getSense())
        {
        case Sense::right:
            this->setSence(Sense::left);
            break;
        case Sense::left:
            this->setSence(Sense::right);
            break;
        }
        break;
    case sign::STOP:
        this->incrementTurn();
        break;
    }
    this->incrementTurn();
}

void Game::incrementTurn()
{
    switch(this->getSense())
    {
    case Sense::right:
        if (this->getTurn()  == this->getPlayers().size() - 1)
        {
            this->getTurn()  = 0;
        }
        else
        {
            this->getTurn()++;
        }
        break;
    case Sense::left:
        if (this->getTurn() == 0)
        {
            this->getTurn() = this->getPlayers().size() - 1;
        }
        else
        {
            this->getTurn()--;
        }
        break;
    }
}

std::vector<Player*> Game::getPlayers()
{
    return this->players;
}

Card& Game::getCurrent()
{
    return this->current;
}

int& Game::getTurn()
{
    return this->turn;
}

Sense Game::getSense()
{
    return this->sense;
}

void Game::setSence(Sense newSence)
{
    this->sense = newSence;
}

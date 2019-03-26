/* Samuel Bismuth 342533064 */
/* Matan Zilka 307949438 */

#include "Game.h"

/**
   Default constructor.
 */
Game::Game()
{
        this->sense = Sense::right;
        this->turn = 0;
}

/**
   DESTRUCTOR.
 */
Game::~Game()
{
        delete []players;
}

/*
   Start function: here is the beginning of the game.
   After the initialization, the program enter in a infinite loop, and get out only if one
   of the player win the game (that is, when he has no card).
 */
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
        // Check if the input are authorized.
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
                players.push_back(new Player(name, nbCards, cards));
        }
}

/*
   This function decide the player for the next turn.
 */
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

/*
   This method properly increment the turn: as a clock wise.
 */
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

/*
   Get players.
 */
std::vector<Player*> Game::getPlayers()
{
        return this->players;
}

/*
   Get current.
 */
Card& Game::getCurrent()
{
        return this->current;
}

/*
   Get turn.
 */
int& Game::getTurn()
{
        return this->turn;
}

Sense Game::getSense()
{
        return this->sense;
}

/*
   Set sence.
 */
void Game::setSence(Sense newSence)
{
        this->sense = newSence;
}

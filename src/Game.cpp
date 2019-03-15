#include "../includes/Game.h"

void Game::start()
{
    initialization();
    while(true)
    {
        Player currentPlayer = this->getPlayers()[this->getTurn()];
        currentPlayer.play(this->getCurrent());
        if (currentPlayer.getNbCards() == 0) {
            cout << currentPlayer.getName() << " wins!" << endl;
            return;
        }
        nextTurn(this->getCurrent());
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
    cout << "How many players?" << endl;
    int nbPlayers;
    cin >>  nbPlayers;
    cout << "How many cards?" << endl;
    int nbCards;
    cin >>  nbCards;
    for (int i = 0; i < nbPlayers; i++)
    {
        cout << "Player number " << i + 1 << " name?" << endl;
        string name;
        cin >>  name;
        vector<Card> cards;
        for (int j = 0; j < nbCards; j++)
        {
            cards.push_back(Card::generate_card());
        }
        Player player(name, nbCards, cards);
        players.push_back(player);
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
        this->getTurn()++;
        break;
    case Sense::left:
        this->getTurn()--;
        break;
    }
}

int Game::operator ++(int nb)
{
    if (nb == this->getPlayers().size())
    {
        nb = 0;
    }
    else
    {
        nb++;
    }
}

int Game::operator --(int nb)
{
    if (nb == 0)
    {
        nb = this->getPlayers().size() - 1;
    }
    else
    {
        nb--;
    }
}

vector<Player> Game::getPlayers()
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

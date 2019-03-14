#include "../includes/Game.h"

void Game::start()
{
    initialization();
    while(true)
    {
        makeRound();
        break;
    }
}

void Game::makeRound()
{
    cout << "current: " <<  this->getCurrent() << endl;
    Player currentPlayer = getPlayers()[this->getTurn()];
    cout << currentPlayer.getName() << ", your turn -" << endl;
    cout << "Your cards: ";
    for(int i = 0; i < currentPlayer.getNbCards(); i++)
    {
        cout << "(" << i + 1 << ")" << currentPlayer.getCards()[i] << " ";
    }
    cout << endl;
    int choice;
    cin >> choice;
    Legal legal = this->isChoiceLegal(choice);
    switch(legal)
    {
    case Legal::notLegal:
        std::cout << "notlegal";
        break;
    case Legal::legal:
        std::cout << "legal";
        break;
    case Legal::cardPb:
        std::cout << "cardpb";
        break;
    }
}

Legal Game::isChoiceLegal(int choice)
{
    Player currentPlayer = getPlayers()[this->getTurn()];
    if (choice < 1 || choice > currentPlayer.getNbCards())
    {
        return Legal::notLegal;
    }
    Card cardChoosed =  getPlayers()[this->getTurn()].getCards()[choice - 1];
    if (cardChoosed.is_legal(this->getCurrent()))
    {
        return Legal::legal;
    }
    else
    {
        return Legal::cardPb;
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

vector<Player> Game::getPlayers()
{
    return this->players;
}

Card Game::getCurrent()
{
    return this->current;
}

int Game::getTurn()
{
    return this->turn;
}

Sense Game::getSense()
{
    return this->sense;
}

#include <stddef.h>
#include <stdio.h>
#include "human.h"
#include "computer.h"
#include "game.h"

BattleShipGame::BattleShipGame(void)
{
    this->players[0] = NULL;
    this->players[1] = NULL;
}

BattleShipGame::~BattleShipGame(void)
{
    for (int i = 0; i < 2; i++)
    {
        if (this->players[i])
        {
            delete this->players[i];
        }
    }
}

bool BattleShipGame::init(void)
{
    // [TODO] 
    // Il faudrait créer deux joueurs, un joueur humain
    // et un joueur ordinateur.
    this->players[0] = new Human("Human");
    this->players[1] = new Computer("Computer");
    return (this->players[0]->start() && this->players[1]->start());
}

void BattleShipGame::play(void)
{
    int i = 0;
    bool playAgain = true;

    // [TODO]
    // Comment s'arrêter sur la condition de victoire ?
    do
    {
        sPosition position = {0};
        if (this->players[i]->play(&position))
        {
            int nextPlayer = i +1;
            if (nextPlayer >= 2)
            {
                nextPlayer = 0;
            }
            eHitResult result = this->players[nextPlayer]->updateShipBoard(&position);
            this->players[i]->updateHistoryBoard(&position, result);
            
            if (++i >= 2)
            {
                i = 0;
            }
        }
        else
        {
            printf("Position invalide ! Veuillez recommencer.\n");
        }
    } while (playAgain);
}

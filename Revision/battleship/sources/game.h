#ifndef _GAME_H_
#define _GAME_H_

#include "player.h"

class BattleShipGame
{
public:
    BattleShipGame(void);
    ~BattleShipGame(void);

    /**
     * @brief Initialisation le début de la partie, 
     * création des joueurs et initialisation des joueurs.
     * 
     * @return true L'initialisation s'est bien passée.
     * @return false Problème lors de l'initialisation, le jeu ne
     * pourra pas démarrer.
     */
    bool init(void);

    void play();

private:
    Player *players[2];
};

#endif /* _GAME_H_ */

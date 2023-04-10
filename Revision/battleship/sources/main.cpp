#include <stdio.h>
#include "game.h"

int main(void)
{
    BattleShipGame game;

    if (game.init())
    {
        game.play();
    }
    else
    {
        printf("Erreur lors de l'initialisation du jeu !\n");
        printf("Le programme doit quitter.\n");
    }

    return 0;
}
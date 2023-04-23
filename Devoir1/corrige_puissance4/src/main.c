#include <stdio.h>
#include <stdbool.h>
#include "utils.h"
#include "p4.h"


/**
 * @brief Affiche des choix à l'utilisateur.
 * 
 * @return Un entier représentant le choix de l'utilisateur.
 */
static int menu(void)
{
    int value = 0;

    do
    {
        printf("1 - Jouer\n");
        printf("2 - Mode test\n");
        printf("3 - Quitter\n");

        value = getIntValue();
    } while (value < 1 || value > 3);
    
    return value;
}

int main(int argc, char *argv[])
{
    bool quit = false;

    do
    {
        switch (menu())
        {
        case 1:
            playP4();
            break;

        case 2:
            testP4();
            break;

        default:
            quit = true;
            break;
        }
    } while (!quit);

    return 0;
}

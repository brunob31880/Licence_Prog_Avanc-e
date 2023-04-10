#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"
#include <stddef.h>
#include <cstdlib>
#include <ctime>
/**
 *
 */
bool askPosition(sPosition *position)
{
    char text[8] = {0};

    if (NULL == position)
    {
        return false;
    }

    printf("Veuillez entrer une position (ex. E4):\n");

    if (NULL != fgets(text, sizeof(text), stdin))
    {
       
        position->ligne = toupper(text[0]) - 'A';
        position->colonne = atoi(&text[1]) - 1;
        if (isPositValid(position,BOARD_LIMIT)==false) {
            cout << "Mauvaise entrée" << endl;
            return false;
        }
    }
    else
    {
        char c;
        while (c != '\n' && c != EOF)
        {
            c = getchar();
        }
    }

    return true;
}
eDirection askDirection(void)
{
    char text[8] = {0};

    printf("Veuillez entrer une direction (0-Hori):\n");
    if (NULL != fgets(text, sizeof(text), stdin))
    {
        if (text[0] == '0')
            return DIR_H;
        else
            return DIR_V;
    }
    else
    {
        char c;
        while (c != '\n' && c != EOF)
        {
            c = getchar();
        }
    }
}

sPosition randomPosition(void)
{
    unsigned seed = time(0);
    srand(seed);
    char lig = 'A' + rand() % 9;
    srand(seed);
    int col = rand() % 10;
    sPosition posit = {lig, col};
    return posit;
}
eDirection randomDirection(void)
{
    unsigned seed = time(0);
    srand(seed);
    int dir = rand() % 2;
    if (dir == 0)
        return DIR_H;
    else
        return DIR_V;
}

bool isPositValid(const sPosition *position, int LIMIT)
{
    if (NULL == position)
    {
        return false;
    }

    if (position->ligne < 0 || position->ligne >= LIMIT)
    {
        return false;
    }

    if (position->colonne < 0 || position->colonne >= LIMIT)
    {
        return false;
    }

    return true;
}
// [TODO]
// Peut-être qu'il faudrait une fonction pour demander
// le sens de placement, horizontal ou vertical.

#include <stdio.h>
#include "board.h"
#include "iostream"
#include "utils.h"
using namespace std;

BattleShipBoard::BattleShipBoard(void)
{
    this->reset();
}

void BattleShipBoard::reset(void)
{
    this->nbrOfShips = 0;

    for (int i = 0; i < BOARD_LIMIT; i++)
    {
        for (int j = 0; j < BOARD_LIMIT; j++)
        {
            shipBoard[i][j] = &water;
            historyBoard[i][j] = ' ';
        }
    }
}

void BattleShipBoard::show(void)
{
    int iteration = 0;
    char letter = 'A';

    printf("\t                Attack history               ");
    printf("\t                Your Ships\n");

    while (iteration < 2)
    {
        printf("\t  ");
        for (int j = 0; j < BOARD_LIMIT; j++)
        {
            printf("  %d ", j + 1);
        }
        iteration++;
    }
    printf("\n");

    iteration = 0;
    while (iteration < 2)
    {
        printf("\t  ");
        for (int j = 0; j < BOARD_LIMIT; j++)
        {
            printf("+---");
        }
        printf("+");
        iteration++;
    }
    printf("\n");

    for (int i = 0; i < BOARD_LIMIT; i++)
    {
        printf("\t%c ", letter);
        for (int j = 0; j < BOARD_LIMIT; j++)
        {
            printf("| %c ", this->historyBoard[i][j]);
        }
        printf("|");

        printf("\t%c ", letter++);
        for (int j = 0; j < BOARD_LIMIT; j++)
        {
            char shipType =
                (this->shipBoard[i][j])
                    ? this->shipBoard[i][j]->getType()
                    : 'X';
            printf("| %c ", shipType);
        }
        printf("|\n");

        printf("\t  ");
        for (int j = 0; j < BOARD_LIMIT; j++)
        {
            printf("+---");
        }
        printf("+");

        printf("\t  ");
        for (int j = 0; j < BOARD_LIMIT; j++)
        {
            printf("+---");
        }
        printf("+\n");
    }
}

bool BattleShipBoard::place(Ship *ship, const sPosition *position, eDirection direction)
{
    int ligneStep = 0, colonneStep = 0;

    if (NULL == ship)
    {
        return false;
    }

    // [TODO]
    // Comment connaître le nombre de cases nécessaires ?
    int shipLife = ship->getLife();
    // cout << "Life boat=" << ship->getLife() << endl;
    if (this->isPositionFree(position, direction, shipLife)==false)
    {
        cout << "Position occupée" << endl;
        return false;
    }

    switch (direction)
    {
    case DIR_V:
        ligneStep = 1;
        break;

    case DIR_H:
        colonneStep = 1;
        break;

    default:
        break;
    }

    int i = position->ligne;
    int j = position->colonne;

    do
    {
        this->shipBoard[i][j] = ship;

        i += ligneStep;
        j += colonneStep;
        shipLife--;
    } while (shipLife > 0);

    this->nbrOfShips++;

    return true;
}

eHitResult BattleShipBoard::hit(const sPosition *position)
{
    if (!this->isPositionValid(position))
    {
        return HitError;
    }

    if (NULL == this->shipBoard[position->ligne][position->colonne])
    {
        return HitError;
    }

    if (&water == this->shipBoard[position->ligne][position->colonne])
    {
        this->shipBoard[position->ligne][position->colonne] = NULL;
        return HitWater;
    }

    bool isSunken = this->shipBoard[position->ligne][position->colonne]->hit();
    this->shipBoard[position->ligne][position->colonne] = NULL;

    if (isSunken)
    {
        this->nbrOfShips--;

        // last boat?
        if (this->isAllSunken())
        {
            return HitWin;
        }
        return HitSunken;
    }

    return HitBoat;
}

void BattleShipBoard::update(const sPosition *position, eHitResult hitResult)
{
    char symbol = '.';

    if (this->isPositionValid(position))
    {
        switch (hitResult)
        {
        case HitBoat:
        case HitSunken:
        case HitWin:
            symbol = 'O';
            break;

        case HitError:
            symbol = 'E';
            break;

        case HitWater:
            symbol = 'X';
            break;

        default:
            break;
        }

        this->historyBoard[position->ligne][position->colonne] = symbol;
    }
    else
    {
        printf("[%s] - Oups....\n", __func__);
        printf("[%s]%d:%d\n", __func__, position->ligne, position->colonne);
    }
}

bool BattleShipBoard::isAlreadyPlayed(const sPosition *position)
{
    if (this->isPositionValid(position))
    {
        if (this->historyBoard[position->ligne][position->colonne] == ' ')
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief Vérifie que la position donnée est valide dans les limites
 * de la grille.
 *
 * @param position Instance d'un objet de type sPosition.
 *
 * @return true La position est valide.
 * @return false La position est hors des limites.
 */
bool BattleShipBoard::isPositionValid(const sPosition *position)
{
    return isPositValid(position, BOARD_LIMIT);
}

/**
 * @brief Vérifie que le navire puisse être inséré à la position donnée.
 *
 * @param position Position où insérer le navire.
 * @param direction Sens de positionnement.
 * @param count Nombre de cases que va occuper le navire.
 *
 * @return true La position est libre.
 * @return false La position est occupée ou invalide.
 */
bool BattleShipBoard::isPositionFree(const sPosition *position, eDirection direction, int count)
{
    int ligneStep = 0, colonneStep = 0;

    if (!isPositionValid(position))
    {
        cout << "Position non valide "<< endl;
        return false;
    }

    switch (direction)
    {
    case DIR_V:
        ligneStep = 1;
        break;

    case DIR_H:
        colonneStep = 1;
        break;

    default:
        break;
    }

    if (ligneStep == 0 && colonneStep == 0)
    {
        return false;
    }

    int i = position->ligne;
    int j = position->colonne;

    do
    {
        if ((i >= BOARD_LIMIT) || (j >= BOARD_LIMIT))
        {
            return false;
        }
        //cout << " ICI " << this->shipBoard[i][j] << "et " << &water << " COUNT=" << count << endl;
        if (this->shipBoard[i][j])
        {

            if (&water != this->shipBoard[i][j])
            {
                return false;
            }
        }

        i += ligneStep;
        j += colonneStep;
        count--;
    } while (count > 0);

    return true;
}

/**
 * @brief Vérifie s'il reste des navires en vie.
 *
 * @return true Plus de navires en vie.
 * @return false Il y a encore des navires en vie.
 */
bool BattleShipBoard::isAllSunken(void)
{
    return (this->nbrOfShips == 0);
}

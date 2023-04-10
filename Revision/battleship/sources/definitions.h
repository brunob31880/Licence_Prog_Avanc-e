#ifndef _DEFINITIONS_H_
#define _DEFINITIONS_H_

#define BOARD_LIMIT 10

/**
 * @brief Définie une position dans la grille de jeu.
 */
typedef struct _position_
{
    int ligne;
    int colonne;
} sPosition;

/**
 * @brief Indique un sens, horizontal ou vertical.
 */
typedef enum _direction_
{
    DIR_H = 0,
    DIR_V,
} eDirection;


#endif

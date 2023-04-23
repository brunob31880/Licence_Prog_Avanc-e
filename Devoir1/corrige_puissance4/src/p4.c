#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include "utils.h"

#define P4_MAX_LIGNE 6
#define P4_MAX_COLS  7

/**
 * Cette macro va être utilisée pour appeler les tests.
 */
#define TEST(func, text, counter) { \
    printf("[TEST] %s\t", text); \
    if (!func()) \
    { \
        counter++; \
        printf("FAIL\n"); \
    } \
    else \
    { \
        printf("PASS\n"); \
    } \
}

/**
 * @brief Tableau à deux dimensions pour représenter le 
 * plateau du jeu.
 */
static char p4_board[P4_MAX_LIGNE][P4_MAX_COLS] = {
    {
        0,
    },
};

/**
 * @brief Nombre maximum de coups autorisés.
 */
static uint16_t p4_max_pion = sizeof(p4_board) / sizeof(p4_board[0][0]);

/**
 * @brief Symboles possibles pour représenter le pion.
 */
static const char p4_pions[2] = {'O', 'X'};

/**
 * @brief Demande à l'utilisateur de choisir une position
 * de jeu, soit un colonne où jouer.
 * 
 * @return Entier représentant la colonne où poser un pion.
 * La première colonne étant identifiée par le numéro 1.
 */
static int dsp_position(void)
{
    int value = 0;

    do
    {
        printf("Choisissez une colonne (1-7) ?\n");
        value = getIntValue();
    } while (value < 1 || value > 7);

    return value;
}

/**
 * @brief Affiche la plateau de jeu à l'écran.
 */
static void dsp_board(void)
{
    int l = 0, c = 0;

    for (l = 0; l < P4_MAX_LIGNE; l++)
    {
        for (c = 0; c < P4_MAX_COLS; c++)
        {
            printf("%c ", p4_board[l][c]);
        }
        printf("\n");
    }
    
    for (l = 0; l < P4_MAX_COLS; l++)
    {
        printf("%d ", l + 1);
    }
    printf("\n");
}

/**
 * @brief Initialise le jeu pour commencer une
 * nouvelle partie.
 */
static void game_init(void)
{
    int l = 0;

    p4_max_pion = sizeof(p4_board) / sizeof(p4_board[0][0]);

    for (l = 0; l < P4_MAX_LIGNE; l++)
    {
        memset(p4_board[l], '.', P4_MAX_COLS * sizeof(char));
    }
}

/**
 * Add a pawn in the column specified.
 * 
 * @param colonne Column to add the pawn.
 * @param pion Pawn represented as a character.
 * @return The line number where the pan has been added,
 * otherwise a negative value (-1).
 */
static int game_push(int colonne, char pion)
{
    int ligne = P4_MAX_LIGNE - 1;

    if (colonne >= P4_MAX_COLS)
    {
        return -1;
    }

    while (ligne >= 0)
    {
        if (p4_board[ligne][colonne] == '.')
        {
            p4_board[ligne][colonne] = pion;
            p4_max_pion--;
            return ligne;
        }

        ligne--;
    }

    return -1;
}

/**
 * @brief Compte le nombre de pions adjacents de même symbole dans une directions.
 * 
 * @param ligne Indice de la ligne de départ.
 * @param colonne Indice de la colonne de départ.
 * @param pasLigne Direction en ligne.
 * @param pasColonne Direction en colonne.
 * @param pion Symbole du pion.
 * @return Le nombre de pions adjacents de même symbole.
 */
static int game_countPawns(int ligne, int colonne, int pasLigne, int pasColonne, char pion)
{
    if (ligne < 0 || ligne >= P4_MAX_LIGNE)
    {
        return 0;
    }

    if (colonne < 0 || colonne >= P4_MAX_COLS)
    {
        return 0;
    }

    if (pion != p4_board[ligne][colonne])
    {
        return 0;
    }

    return 1 + game_countPawns(ligne + pasLigne, colonne + pasColonne, pasLigne, pasColonne, pion);
}

/**
 * @brief Détermine s'il y a une victoire, donc l'alignement de 4 pions
 * de même couleur.
 * 
 * @param ligne Ligne où commencer la recherche.
 * @param colonne Colonne où commencer la recherche.
 * @param pion Symbole du pion joué.
 * @return true Il y a 4 pions de même symbole alignés.
 * @return false Il n'y a pas d'alignement, donc pas de victoire.
 */
static bool game_isVictory(int ligne, int colonne, const char pion)
{
    /* diagonale / */
    if (4 <= (1 + game_countPawns(ligne - 1, colonne + 1, -1, 1, pion) + game_countPawns(ligne + 1, colonne - 1, 1, -1, pion)))
    {
        return true;
    }
    /* horizontale - */
    if (4 <= (1 + game_countPawns(ligne, colonne -1, 0, -1, pion) + game_countPawns(ligne, colonne + 1, 0, 1, pion)))
    {
        return true;
    }
    /* verticale   | */
    if (4 <= (1 + game_countPawns(ligne - 1, colonne, -1, 0, pion) + game_countPawns(ligne + 1, colonne, 1, 0, pion)))
    {
        return true;
    }
    /* diagonale   \ */
    if (4 <= (1 + game_countPawns(ligne - 1, colonne - 1, -1, -1, pion) + game_countPawns(ligne + 1, colonne + 1, 1, 1, pion)))
    {
        return true;
    }

    return false;
}

/**
 * @brief Indique s'il n'y a plus de coups possibles.
 * 
 * @return true Plus de coups possibles
 * @return false Il y a encore des coups possibles.
 */
static bool game_isFinished(void)
{
    return (0 == p4_max_pion);
}

void playP4(void)
{
    int colonne = 0;
    int ligne = 0;
    int indice_pion = 0;

    printf("Puissance 4 - v1.0\n");

    game_init();

    while(!game_isFinished())
    {
        dsp_board();
        colonne = dsp_position();
        /* la fonction retourne un choix entre 1 et x
         * mais les indices de tableaux sont entre 0 et x */
        colonne -= 1;
        ligne = game_push(colonne, p4_pions[indice_pion]);
        if (ligne >= 0)
        {
            if (game_isVictory(ligne, colonne, p4_pions[indice_pion]))
            {
                dsp_board();
                printf("Le joueur au pion '%c' gagne :)\n", p4_pions[indice_pion]);
                return;
            }
            
            if (++indice_pion > 1)
            {
                indice_pion = 0;
            }
        }
    }

    printf("Match nul :/\n");
}

/*********************************************************/
/* TESTS */
/*********************************************************/

static bool test_game_init(void)
{
    char expected[P4_MAX_LIGNE * P4_MAX_COLS] = {0,};

    memset(expected, '.', sizeof(expected) / sizeof(expected[0]));
    game_init();

    return (0 == memcmp(expected, p4_board, P4_MAX_LIGNE * P4_MAX_COLS));
}

static bool test_game_max_pions(void)
{
    game_init();

    return ((P4_MAX_LIGNE * P4_MAX_COLS) == p4_max_pion);
}

static bool test_game_push(void)
{
    int ligne = 0, colonne = 0;
    char pion = 'O';

    game_init();

    /* must not add a pawn out of the board */
    if (game_push(P4_MAX_COLS, pion) >= 0)
    {
        return false;
    }

    for (colonne = 0; colonne < P4_MAX_COLS; colonne++)
    {
        for (ligne = 0; ligne < P4_MAX_LIGNE; ligne++)
        {
            game_push(colonne, pion);
        }
        if (game_push(colonne, pion) >= 0)
        {
            return false;
        }
    }

    return true;
}

static bool test_game_NoVictory(void)
{
    int ligne = 0, colonne = 0;
    char test_board[P4_MAX_LIGNE][P4_MAX_COLS] = {
        {'O', 'O', 'X', 'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O', 'X', 'X', 'O'},
        {'O', 'O', 'X', 'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O', 'X', 'X', 'O'},
        {'O', 'O', 'X', 'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O', 'X', 'X', 'O'},
    };

    memcpy(p4_board, test_board, sizeof(test_board));

    for (ligne = 0; ligne < P4_MAX_LIGNE; ligne++)
    {
        for (colonne = 0; colonne < P4_MAX_COLS; colonne++)
        {
            if (game_isVictory(ligne, colonne, p4_board[ligne][colonne]))
            {
                return false;
            }
        }
    }

    return true;
}

static bool test_game_VictoryColumn(void)
{
    int colonne = 0;
    char test_board[P4_MAX_LIGNE][P4_MAX_COLS] = {
        {'O', 'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'X', 'O', 'X', 'O'},
        {'X', 'O', 'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X', 'O', 'X'},
    };

    memcpy(p4_board, test_board, sizeof(test_board));

    for (colonne = 0; colonne < P4_MAX_COLS; colonne++)
    {
        if (!game_isVictory(0, colonne, p4_board[0][colonne]))
        {
            return false;
        }
    }

    return true;
}

static bool test_game_VictoryRow(void)
{
    int ligne = 0;
    char test_board[P4_MAX_LIGNE][P4_MAX_COLS] = {
        {'O', 'O', 'O', 'O', '.', '.', '.'},
        {'X', 'X', 'X', 'X', '.', '.', '.'},
        {'O', 'O', 'O', 'O', '.', '.', '.'},
        {'X', 'X', 'X', 'X', '.', '.', '.'},
        {'O', 'O', 'O', 'O', '.', '.', '.'},
        {'X', 'X', 'X', 'X', '.', '.', '.'},
    };

    memcpy(p4_board, test_board, sizeof(test_board));

    for (ligne = 0; ligne < P4_MAX_LIGNE; ligne++)
    {
        if (!game_isVictory(ligne, 0, p4_board[ligne][0]))
        {
            return false;
        }
    }

    return true;
}

static bool test_game_countimits(void)
{
    if (0 != game_countPawns(-1, 0, -1, 1, '0'))
    {
        return false;
    }

    if (0 != game_countPawns(P4_MAX_LIGNE, 0, 1, 1, '0'))
    {
        return false;
    }

    if (0 != game_countPawns(0, -1, 1, 1, '0'))
    {
        return false;
    }

    if (0 != game_countPawns(0, P4_MAX_COLS, 1, 1, '0'))
    {
        return false;
    }

    return true;
}

static bool test_game_VictoryDiag(void)
{
    char test_board[P4_MAX_LIGNE][P4_MAX_COLS] = {
        {'O', '.', '.', '.', '.', 'X', '.'},
        {'X', 'O', '.', '.', 'X', '.', '.'},
        {'.', 'X', 'O', 'X', '.', '.', '.'},
        {'.', '.', 'X', 'O', '.', '.', '.'},
        {'.', '.', '.', 'X', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.'},
    };

    memcpy(p4_board, test_board, sizeof(test_board));

    if (!game_isVictory(0, 0, p4_board[0][0]))
    {
        return false;
    }

    if (!game_isVictory(1, 0, p4_board[1][0]))
    {
        return false;
    }

    if (!game_isVictory(0, 5, p4_board[0][5]))
    {
        return false;
    }

    return true;
}

static bool test_game_isFinished(void)
{
    int ligne, colonne;

    game_init();

    for (colonne = 0; colonne < P4_MAX_COLS; colonne++)
    {
        for (ligne = 0; ligne < P4_MAX_LIGNE; ligne++)
        {
            game_push(colonne, 'O');
        }
    }

    return game_isFinished();
}

bool testP4(void)
{
    int fails = 0;

    TEST(test_game_init, "Initialisation du jeu...", fails);
    TEST(test_game_max_pions, "Initialisation du nombre de pions...", fails);
    TEST(test_game_push, "En dehors des limites...", fails);
    TEST(test_game_NoVictory, "Pas de victoire...", fails);
    TEST(test_game_VictoryColumn, "Victoire en colonne...", fails);
    TEST(test_game_VictoryRow, "Victoire en ligne...", fails);
    TEST(test_game_countimits, "Limites du plateau...", fails);
    TEST(test_game_VictoryDiag, "Victoire en diagonale...", fails);
    TEST(test_game_isFinished, "Jeu nul...", fails);

    printf("%d test(s) en échec\n", fails);

    return (0 == fails);
}

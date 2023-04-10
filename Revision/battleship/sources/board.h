#ifndef _BOARD_H_
#define _BOARD_H_

#include "definitions.h"
#include "ship.h"

/**
 * @brief 
 * 
 */
typedef enum _eHitResult_
{
    HitError = 0, // Problème lors du tire
    HitWater, // L'eau est touchée
    HitBoat, // Navire touché
    HitSunken, // Navire coulé
    HitWin, // Plus de navires, c'est gagné
} eHitResult;

class BattleShipBoard
{
public:
    BattleShipBoard(void);

    /**
     * @brief Initialise les grilles de jeu avec des
     * valeurs par défaut.
     */
    void reset(void);

    /**
     * @brief Affiche les deux grilles pour que le joueur ait
     * une vue de son jeu.
     */
    void show(void);

    /**
     * @brief Place un navire sur la grille. La position et le sens
     * sont indiqués en paramètres.
     * 
     * @param ship Navire à positionner.
     * 
     * @return true Le navire est placé.
     * @return false La place est occupée ou invalide.
     */
    bool place(Ship *ship, const sPosition *position, eDirection direction);

    /**
     * @brief Tire à la position indiquée.
     * 
     * @param position Position dans la grille de jeu, ligne/colonne.
     * 
     * @return eHitResult Le résultat dépend du tire :
     * HitError - Erreur lors de l'exécution.
     * HitWater - tire tombé dans l'eau.
     * HitBoat - navire touché.
     * HitSunken - navire coulé.
     * HitWin - Victoire, il n'y a plus de navires.
     */
    eHitResult hit(const sPosition *position);

    /**
     * @brief Mise à jour de la grille d'historique pour conserver
     * l'historique des attaques et le résultat.
     * 
     * @param position 
     * @param hitResult 
     */
    void update(const sPosition *position, eHitResult hitResult);

    /**
     * @brief Vérifie si la position est déjà jouée.
     * 
     * @param position Position à vérifier.
     * 
     * @return true Position déjà jouée.
     * @return false Position non jouée.
     */
    bool isAlreadyPlayed(const sPosition *position);

private:
    bool isPositionValid(const sPosition *position);
    bool isPositionFree(const sPosition *position, eDirection direction, int count);
    bool isAllSunken(void);

private:
    /** Grille où sont positionnés les navires */
    Ship* shipBoard[BOARD_LIMIT][BOARD_LIMIT];
    /** Grille des coups joués */
    char historyBoard[BOARD_LIMIT][BOARD_LIMIT];
    /** Number of ships in the board */
    int nbrOfShips;
    /** */
    ShipWater water;
};

#endif /* _BOARD_H_ */
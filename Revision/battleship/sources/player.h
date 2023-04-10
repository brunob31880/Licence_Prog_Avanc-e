#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "board.h"
#include "ship.h"

class Player
{
public:
    Player(const char *name);
    virtual ~Player(void);

    /**
     * @brief Retourne un pointeur sur le nom du joueur.
     * 
     * @return Nom du joueur.
     */
    const char *getName(void) const;

    /**
     * @brief Invite le joueur à remplir sa grille en lui 
     * demandant de placer ses navires.
     * 
     * @return true Le jeu peut démarrer.
     * @return false Erreur lors de l'initialisation
     */
    virtual bool start(void) = 0;

    /**
     * @brief Invite le joueur à entrer une position pour 
     * lancer une attaque sur la grille adverse
     * 
     * @param position Instance pour enregistrer la position
     * entrée par le joueur.
     * 
     * @return true La position est entrée.
     * @return false Pointeur NULL.
     */
    virtual bool play(sPosition *position) = 0;

    /**
     * @brief Met à jour la grille de navires en fonction de la position
     * jouée par le joueur adverse. Retourne le résultat du tire adverse.
     * 
     * @param position Position utilisée pour l'attaque adverse.
     * 
     * @return eHitResult Résultat de l'attaque adverse.
     */
    eHitResult updateShipBoard(const sPosition *position);

    /**
     * @brief Met à jour la grille d'historique du joueur avec le résultat
     * obtenu du joueur adverse.
     * 
     * @param position Position utilisée pour l'attaque.
     * @param hitResult Résultat de l'attaque pour mettre à jour
     * la grille d'attaque. 
     */
    void updateHistoryBoard(const sPosition *position, eHitResult hitResult);

protected:
    BattleShipBoard gameBoard;
    Ship *ships[5];

private:
    char *name;
};

#endif /* _PLAYER_H_ */

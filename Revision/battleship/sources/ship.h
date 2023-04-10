#ifndef _SHIP_H_
#define _SHIP_H_

#include "definitions.h"

class Ship
{
public:
    Ship(void);
    virtual ~Ship(void);

    /**
     * @brief Retourne la santé d'un navire, équivalent
     * au nombre de cases dans une grille.
     * 
     * @return int Santé du navire, 0 idique qu'il est coulé.
     */
    int getLife(void) const;

    /**
     * @brief Retourne le type de navire.
     * 
     * @return Caractère représentant le type de navire.
     */
    virtual char getType(void) const = 0;

    /**
     * @brief Indique que le navire est touché. Il perd un
     * point de santé.
     * 
     * @return true Le navire est coulé. Plus de points de santé.
     * @return false La navire n'est pas coulé.
     */
    bool hit(void);

protected:
    /** santé du navire, dépendant de son type */
    int life;
};

class ShipCarrier: public Ship
{
public:
    ShipCarrier(void);
    ~ShipCarrier(void);
    char getType(void) const;
};

class ShipBattleship: public Ship
{
public:
    ShipBattleship(void);
    ~ShipBattleship(void);
    char getType(void) const;
};

class ShipCruiser: public Ship
{
public:
    ShipCruiser(void);
    ~ShipCruiser(void);
    char getType(void) const;
};

class ShipSubmarine: public Ship
{
public:
    ShipSubmarine(void);
    ~ShipSubmarine(void);
    char getType(void) const;
};

class ShipWater: public Ship
{
public:
    char getType(void) const;
};

#endif /* _SHIP_H_ */

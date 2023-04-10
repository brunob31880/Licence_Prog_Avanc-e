#include "ship.h"
#include <stdio.h>

Ship::Ship(void)
{

}

Ship::~Ship(void)
{

}

int Ship::getLife(void) const
{
    return life;
}

bool Ship::hit(void)
{
    if (life > 0)
    {
        life--;
    }

    return (life == 0);
}

ShipCarrier::ShipCarrier(void)
{
    this->life = 5;
}

ShipCarrier::~ShipCarrier(void)
{

}

char ShipCarrier::getType(void) const
{
    return 'C';
}

ShipBattleship::ShipBattleship(void)
{
    this->life = 4;
}

ShipBattleship::~ShipBattleship(void)
{
    
}

char ShipBattleship::getType(void) const
{
    return 'B';
}

ShipCruiser::ShipCruiser(void)
{
    this->life = 3;
}

ShipCruiser::~ShipCruiser(void)
{
    
}

char ShipCruiser::getType(void) const
{
    return 'R';
}

ShipSubmarine::ShipSubmarine(void)
{
    this->life = 2;
}

ShipSubmarine::~ShipSubmarine(void)
{
    
}

char ShipSubmarine::getType(void) const
{
    return 'S';
}

char ShipWater::getType(void) const
{
    return '.';
}

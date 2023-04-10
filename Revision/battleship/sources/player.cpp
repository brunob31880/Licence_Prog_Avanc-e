#include <string.h>
#include "player.h"

Player::Player(const char *name)
{
    const char* theName = "Unknown";

    if (name)
    {
        theName = name;
    }

    this->name = new char[strlen(name) + 1];
    this->name[0] = '\0';
    strncat(this->name, theName, strlen(theName));

    this->ships[0] = new ShipCarrier();
    this->ships[1] = new ShipBattleship();
    this->ships[2] = new ShipCruiser();
    this->ships[3] = new ShipCruiser();
    this->ships[4] = new ShipSubmarine();
}

Player::~Player(void)
{
    if (this->name)
    {
        delete[] this->name;
    }

    for (int i = 0; i < 5; i++)
    {
        if (this->ships[i])
        {
            delete this->ships[i];
        }
    }
}

const char *Player::getName(void) const
{
    return this->name;
}

eHitResult Player::updateShipBoard(const sPosition *position)
{
    return this->gameBoard.hit(position);
}

void Player::updateHistoryBoard(const sPosition *position, eHitResult hitResult)
{
    this->gameBoard.update(position, hitResult);
}


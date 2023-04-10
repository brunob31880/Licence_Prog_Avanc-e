
#include <iostream>

using namespace std;
#include "computer.h"
#include "utils.h"

Computer::Computer(const char *name)
    : Player(name)
{
    this->lastPosition.ligne = 0;
    this->lastPosition.colonne = 0;
}

Computer::~Computer(void)
{
}

bool Computer::start(void)
{
    // [TODO]
    // Placement libre.

    cout << "Debut pour " << this->getName() << endl;
    int nb = sizeof this->ships / sizeof this->ships[0];
    sPosition posit;
    eDirection dir;
    for (int i = 0; i < nb; i++)
    {
        cout << "==== Placement de " << this->ships[i]->getType() << "======" << endl;
        do
        {
            posit = randomPosition();
            dir = randomDirection();
        } while (this->gameBoard.place(this->ships[i], &posit, dir) == false);
        cout << "Placement de " << this->ships[i]->getType() << " a la position " << posit.ligne << "," << posit.colonne << endl;
        this->gameBoard.show();
    }
    return true;
}

bool Computer::play(sPosition *position)
{
    // [TODO]
    // Logique libre.
    return true;
}

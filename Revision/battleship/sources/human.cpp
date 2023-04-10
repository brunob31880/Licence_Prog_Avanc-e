#include <iostream>

#include "human.h"
#include "utils.h"

using namespace std;

Human::Human(const char *name)
    : Player(name)
{
}

Human::~Human(void)
{
}

bool Human::play(sPosition *position)
{
    // [TODO]
    // Afficher les grilles historique et navires.
    // Demander une position de jeu non jouée.
    return true;
}

bool Human::start(void)
{
    // [TODO]
    // Demander au joueur d'entrer des coordonées (A0, E4, etc.), un sens
    // (horizonta, vertical), place le navire dans la bonne grille.
    // Répéter l'opération pour les cinq navires.
    cout << "Debut pour " << this->getName() << endl;
    int nb = sizeof this->ships / sizeof this->ships[0];
    sPosition posit;
     eDirection dir;
    for (int i = 0; i < nb; i++)
    {
        cout << "==== Placement de " << this->ships[i]->getType() << "======" << endl;
        do
        {           
            while (askPosition(&posit) == false)
            {
                cout << "Entrée incorrecte " << endl;
            }
            dir = askDirection();
            cout << "Placement incorrect " << endl;
        } while (this->gameBoard.place(this->ships[i], &posit, dir) == false);
        cout << "Placement de " << this->ships[i]->getType() << " a la position " << posit.ligne << "," << posit.colonne << endl;
        this->gameBoard.show();
    }
    return true;
}

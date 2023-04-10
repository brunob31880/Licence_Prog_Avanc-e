
#include <iostream>
using namespace std;

#include "cadre.h"


Cadre::Cadre( const char* nom, double salaire, double prime )
: Employe( nom, salaire ) /* appel au constructeur parent */
{
	this->prime = prime;
}

void Cadre::presentation( void )
{
	/* appel de la methode de base du parent qui affichera le nom et le salaire
	 * puis nous completons la fonction en affichant le status. */
	Employe::presentation();
	cout << "Statut : Cadre" << endl;
	cout << "Prime : " << prime << endl;
}


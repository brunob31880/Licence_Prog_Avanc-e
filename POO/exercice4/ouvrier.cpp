
#include <iostream>
using namespace std;

#include "ouvrier.h"


Ouvrier::Ouvrier( const char* nom, double salaire )
: Employe( nom, salaire ) /* appel au constructeur parent */
{
}

void Ouvrier::presentation( void )
{
	/* appel de la methode de base du parent qui affichera le nom et le salaire
	 * puis nous completons la fonction en affichant le status. */
	Employe::presentation();
	cout << "Statut : Ouvrier" << endl;
}


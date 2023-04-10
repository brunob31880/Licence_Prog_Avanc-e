
#include <iostream>
using namespace std;

#include "cadrecom.h"


CadreCom::CadreCom( const char* nom, double salaire, double interessement, double chiffre_ventes )
: Employe( nom, salaire ) /* appel au constructeur parent */
{
	this->interessement = interessement;
	this->chiffre_ventes = chiffre_ventes;
}

void CadreCom::presentation( void )
{
	/* appel de la methode de base du parent qui affichera le nom et le salaire
	 * puis nous completons la fonction en affichant le status. */
	Employe::presentation();
	cout << "Statut : Cadre Commercial" << endl;
	cout << "Interessement : " << interessement << endl;
	cout << "Chiffre vente : " << chiffre_ventes << endl;
}



#include <iostream>
using namespace std;

#include <stddef.h>
#include <string.h>
#include "employe.h"

Employe::Employe( const char* nom, double salaire )
{
	/* les variables des arguments ont le meme nom que les variables
	 * attributs de la classe. Dans ce cas, par defaut c'est la variable argument qui sera
	 * prise en compte, et il faut utiliser this-> pour faire reference a la variable de
	 * la classe.
	 * nom : fait reference a l'argument
	 * this->nom : fait reference a la variable attribut de Employe
	 */
	/* this est vu comme un pointeur sur l'instance courante de la classe */
	this->nom[0] = '\0';
	if( NULL != nom ) /* ici nom est la variable argument */
	{
		strncat( this->nom, nom, sizeof( this->nom ) - 1 );
	}

	this->salaire = salaire;
}

void Employe::presentation( void )
{
	/* pas besoin d'utiliser this car il n'y pas d'ambiguite sur le nom des variables ici */
	cout << "Nom : " << nom << endl;
	cout << "Salaire : " << salaire << endl;
}

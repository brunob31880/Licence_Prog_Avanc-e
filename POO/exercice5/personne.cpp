
#include <iostream>
using namespace std;

#include <string.h>
#include "personne.h"


Personne::Personne(
		const char* n,
		const char* p,
		int jour, int mois, int annee,
		t_sexe s )
{
	nom[0] = '\0';
	if( NULL != n ) { strncat( nom, n, sizeof( nom ) - 1 ); }
	prenom[0] = '\0';
	if( NULL != p ) { strncat( prenom, p, sizeof( prenom ) - 1 ); }
	date_naissance = new Date( jour, mois, annee );
	sexe = s;
}

Personne::~Personne( void )
{
	delete date_naissance;
}

void Personne::affiche( void )
{
	cout << prenom << " " << nom << endl;
	cout << (( sexe == SEXE_HOMME ) ? "Homme" : "Femme") << endl;
	date_naissance->affiche();
}

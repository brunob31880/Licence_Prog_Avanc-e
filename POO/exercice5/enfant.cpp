
#include <iostream>
using namespace std;

#include "enfant.h"


Enfant::Enfant(
		const char* n, const char* p,
		int jour, int mois, int annee,
		t_sexe s,
		Adulte* per,
		Adulte* mer )
: Personne( n, p, jour, mois, annee, s )
{
	pere = per;
	mere = mer;
}

void Enfant::affiche( void )
{
	Personne::affiche();
	if( NULL != pere )
	{
		cout << "Pere :" << endl;
		pere->Personne::affiche();
	}
	if( NULL != mere )
	{
		cout << "Mere :" << endl;
		mere->Personne::affiche();
	}
}


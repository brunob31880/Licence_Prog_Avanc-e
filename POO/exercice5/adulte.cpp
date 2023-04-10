
#include <iostream>
using namespace std;

#include "adulte.h"


Adulte::Adulte(
		const char* n, const char* p,
		int jour, int mois, int annee,
		t_sexe s,
		Adulte* c,
		t_situation sit )
: Personne( n, p, jour, mois, annee, s )
{
	conjoint = c;
	situation = sit;
}

void Adulte::affiche( void )
{
	Personne::affiche();
	cout << get_situation_name() << endl;
	if( NULL != conjoint )
	{
		cout << "Conjoint :" << endl;
		/* si on apelle la methode affiche du conjoint on va creer une boucle infinie.
		 * pour faire simple on se contente d'afficher les informations de base du conjoint. */
		conjoint->Personne::affiche();
	}
}

const char* Adulte::get_situation_name( void )
{
	switch( situation )
	{
	case SIT_CELIBATAIRE:
		return "Celibataire";

	case SIT_DIVORCE:
		return "Divorce";

	case SIT_MARIE:
		return "Marie";

	case SIT_VEUF:
		return "Veuf";

	default:
		break;
	}

	return "Situation inconnue";
}


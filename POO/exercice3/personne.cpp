
#include <string.h>
#include "personne.h"


Personne::Personne( void )
{
	nom[0] = '\0';
	prenom[0] = '\0';
}

Personne::~Personne( void )
{

}

void Personne::init(
		const char* n,
		const char* p,
		int j, int m, int a )
{
	strncat( nom, n, sizeof( nom ) - 1 );
	strncat( prenom, p, sizeof( prenom ) - 1 );
	naissance.init( j, m, a );
}

const char* Personne::get_nom( void ) const
{
	return nom;
}

const char* Personne::get_prenom( void ) const
{
	return prenom;
}

const Date* Personne::get_date_naissance( void ) const
{
	return &naissance;
}

bool Personne::compare( const Personne* p )
{
	bool rc = false;

	do
	{
		/* strcmp retourne 0 si deux chaines sont identiques */
		if( 0 != strcmp( nom, p->get_nom() )) { break; }
		if( 0 != strcmp( prenom, p->get_prenom() )) { break; }
		if( !naissance.compare( p->get_date_naissance() ) ) { break; }

		rc = true;
	}
	while( 0 );

	return rc;
}

int Personne::age( int a )
{
	return a - naissance.annee;
}

bool Personne::majeur( const Date* d )
{
	Date d2;

	/* j'utilise une objet secondaire pour ne pas modifier
	 * celui donne en argument. */
	d2.init( d->jour, d->mois, d->annee - 18 );
	return naissance.anterieur( &d2 );
}

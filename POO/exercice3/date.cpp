
#include "date.h"


Date::Date( void )
{
	jour = 0;
	mois = 0;
	annee = 0;
}

Date::~Date( void )
{

}

void Date::init( int j, int m, int a )
{
	jour = j;
	mois = m;
	annee = a;
}

bool Date::anterieur( const Date* d )
{
	if( annee < d->annee ) { return true; }
	if( annee > d->annee ) { return false; }
	if( mois < d->mois ) { return true; }
	if( mois > d->mois ) { return false; }
	if( jour < d->jour ) { return true; }
	if( jour >= d->jour ) { return false; }

	return false;
}

bool Date::compare( const Date* d )
{
	bool rc = false;

	do
	{
		if( annee != d->annee ) { break; }
		if( mois != d->mois ) { break; }
		if( jour != d->jour ) { break; }

		rc = true;
	}
	while( 0 );

	return rc;
}


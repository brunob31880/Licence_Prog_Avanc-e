
#include "date.h"


Date::Date( void )
{
	jour = 0;
	mois = 0;
}

Date::~Date( void )
{

}

void Date::init( int j, int m )
{
	jour = j;
	mois = m;
}

void Date::lendemain( void )
{
	/* Pour cette methode, on regarde d'abord si la date correspond
	 * au dernier jour d'un mois, voire d'une annee. */
	switch( mois )
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if( 31 != jour ) { jour++; }
		else
		{
			jour = 1;
			if( 12 != mois ) { mois++; }
			else
			{
				/* annee suivante */
				mois = 1;
			}
		}

		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if( 30 != jour ) { jour++; }
		else
		{
			jour = 1;
			mois++;
		}

		break;
	}

	case 2:
	{
		/* on ne gere pas les annees bissextiles */
		if( 28 != jour ) { jour++; }
		else
		{
			jour = 1;
			mois++;
		}

		break;
	}
	}
}

bool Date::finmois( void )
{
	/* en C++ on peut utiliser le type bool qui prend les valeurs
	 * true et false. Mais on aurait pu tout aussi bien utiliser un
	 * type standard. */
	bool rc = false;

	switch( mois )
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if( 31 == jour ) { rc = true; }

		break;
	}

	case 4:
	case 6:
	case 9:
	case 11:
	{
		if( 30 == jour ) { rc = true; }

		break;
	}

	case 2:
	{
		/* on ne gere pas les annees bissextiles */
		if( 28 == jour ) { rc = true; }

		break;
	}
	}

	return rc;
}

bool Date::anterieur( const Date* d )
{
	if( mois < d->mois ) { return true; }
	if( mois > d->mois ) { return false; }
	if( jour < d->jour ) { return true; }
	if( jour >= d->jour ) { return false; }

	return false;
}


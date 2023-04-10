
#include "ListeFacture.h"

ListeFacture::ListeFacture( void )
{

}

ListeFacture::~ListeFacture( void )
{

}

double ListeFacture::somme_fin_mois( void )
{
	int i = 0;
	double result = 0;

	for( i = 0; i < 100; i++ )
	{
		if( factures[i].finmois() )
		{
			result += factures[i].montant;
		}
	}

	return result;
}

void ListeFacture::repousse( int nclient )
{
	int i = 0;

	for( i = 0; i < 100; i++ )
	{
		if( nclient == factures[i].num_client &&
			!factures[i].finmois() )
		{
			factures[i].lendemain();
		}
	}
}

double ListeFacture::somme_anterieur( const Date* d )
{
	int i = 0;
	double result = 0;

	for( i = 0; i < 100; i++ )
	{
		if( factures[i].anterieur( d ) )
		{
			result += factures[i].montant;
		}
	}

	return result;
}



#include "population.h"

Population::Population( void )
{

}

Population::~Population( void )
{

}

double Population::age_moyen( int annee )
{
	int i = 0;
	double result = 0;

	for( i = 0; i < 20; i++ )
	{
		result += personnes[i].age( annee );
	}

	return result / 20;
}




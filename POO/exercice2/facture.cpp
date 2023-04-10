
#include "facture.h"


Facture::Facture( void )
{
	num_facture = 0;
	num_client = 0;
	montant = 0;
}

Facture::~Facture( void )
{

}

void Facture::lendemain( void )
{
	/* il faut simplement appeler la methode de l'objet Date */
	date.lendemain();
}

bool Facture::finmois( void )
{
	return date.finmois();
}

bool Facture::anterieur( const Date* d )
{
	return date.anterieur( d );
}

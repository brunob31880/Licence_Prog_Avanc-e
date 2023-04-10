
#ifndef _LISTEFACTURE_H_
#define _LISTEFACTURE_H_

/* pour qu'un objet Facture soit connu */
#include "facture.h"

class ListeFacture
{
public:
	ListeFacture( void );
	~ListeFacture( void );

	/**
	 * Donne la somme de toutes les factures de fin de mois.
	 *
	 * @return somme de toutes les factures de fin de mois.
	 */
	double somme_fin_mois( void );
	/**
	 * Repousse au lendemain les factures ayant le meme numero
	 * de client que celui donne en argument, excepte les factures
	 * datant de la fin du mois.
	 *
	 * @param nclient
	 */
	void repousse( int nclient );
	/**
	 * Donne la somme des montants des factures anterieures a la
	 * date donnee.
	 *
	 * @param d   Objet de type Date.
	 *
	 * @return somme des montants des factures anterieures a la
	 *         date donnee
	 */
	double somme_anterieur( const Date* d );


private:
	/* tableau de 100 factures */
	Facture factures[100];
};


#endif

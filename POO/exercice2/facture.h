
#ifndef _FACTURE_H_
#define _FACTURE_H_

/* pour que le type Date soit connu */
#include "date.h"

class Facture
{
public:
	Facture( void );
	~Facture( void );

	/**
	 * Change la date actuelle pour le lendemain.
	 */
	void lendemain( void );
	/**
	 * Indique si la facture est datee du dernier
	 * jour du mois.
	 *
	 * @return true, datee du dernier jour du mois, sinon false.
	 */
	bool finmois( void );
	/**
	 * Determine si la date actuelle est anterieure a celle
	 * donnee en argument.
	 *
	 * @param d   Objet de type Date.
	 *
	 * @return true, la date actuelle est anterieure, sinon false.
	 */
	bool anterieur( const Date* d );

	/* je suppose les attributs publiques pour y avoir
	 * acces facilement en dehors de la classe. Sinon
	 * on peut les declarer prives et utiliser des methodes
	 * publiques pour les initialser et le recuperer. */
public:
	int num_facture;
	int num_client;
	Date date;
	double montant;
};


#endif


#ifndef _POPULATION_H_
#define _POPULATION_H_

#include "personne.h"

class Population
{
public:
	Population( void );
	~Population( void );

	/**
	 * Donne l'age moyen de la population pour une annee donnee.
	 *
	 * @param annee   Annee de reference.
	 *
	 * @return age moyen de la population pour l'annee donnee.
	 */
	double age_moyen( int annee );

private:
	Personne personnes[20];
};


#endif

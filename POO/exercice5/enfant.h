
#ifndef ENFANT_H_
#define ENFANT_H_

#include "personne.h"
#include "adulte.h"


class Enfant : public Personne
{
public:
	Enfant( const char* n, const char* p,
		int jour, int mois, int annee,
		t_sexe s,
		Adulte* per,
		Adulte* mer );

	void affiche( void );

private:
	Adulte *pere, *mere;
};


#endif /* ENFANT_H_ */

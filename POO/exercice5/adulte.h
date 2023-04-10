
#ifndef ADULTE_H_
#define ADULTE_H_


#include "personne.h"

typedef enum
{
	SIT_CELIBATAIRE,
	SIT_MARIE,
	SIT_DIVORCE,
	SIT_VEUF,
} t_situation;


class Adulte : public Personne
{
public:
	Adulte(
			const char* n, const char* p,
			int jour, int mois, int annee,
			t_sexe s,
			Adulte* c,
			t_situation sit );

	void affiche( void );

private:
	const char* get_situation_name( void );

private:
	Adulte* conjoint;
	t_situation situation;
};


#endif /* ADULTE_H_ */

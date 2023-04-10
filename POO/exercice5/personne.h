
#ifndef PERSONNE_H_
#define PERSONNE_H_

typedef enum
{
	SEXE_HOMME,
	SEXE_FEMME,
} t_sexe;


class Personne
{
public:
	Personne(
			const char* n,
			const char* p,
			int jour, int mois, int annee,
			t_sexe s );
	virtual ~Personne( void );

	virtual void affiche( void );

private:
	char nom[64];
	char prenom[64];
	Date* date_naissance;
	t_sexe sexe;
};


#endif /* PERSONNE_H_ */

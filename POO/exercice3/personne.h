
#ifndef _PERSONNE_H_
#define _PERSONNE_H_

#include "date.h"

class Personne
{
public:
	Personne( void );
	~Personne( void );

	/**
	 * Permet d'initialiser les attributs d'une personne.
	 *
	 * @param n   Nom de la personne.
	 * @param p   Prenom de la personne.
	 * @param j   Jour de naissance.
	 * @param m   Mois de naissance.
	 * @param a   Annee de naissance.
	 */
	void init(
			const char* n, const char* p,
			int j, int m, int a );
	/**
	 * Accesseur pour recuperer le nom de la personne.
	 */
	const char* get_nom( void ) const;
	/**
	 * Accesseur pour recuperer le prenom de la personne.
	 */
	const char* get_prenom( void ) const;
	/**
	 * Accesseur pour recupere la date de naissance.
	 */
	const Date* get_date_naissance( void ) const;
	/**
	 * Compare la personne actuelle et celle donnee en argument.
	 *
	 * @param p   Objet de type Personne.
	 *
	 * @return true si les deux personnes sont identiques, sinon
	 *         false.
	 */
	bool compare( const Personne* p );
	/**
	 * Donne l'age de la personne pour l'annee donnee.
	 *
	 * @param a   Annee de reference.
	 *
	 * @return l'age de la personne.
	 */
	int age( int a );
	/**
	 * Indique si la personne est majeure.
	 *
	 * @param d   Date courante.
	 *
	 * @return true, la personne est majeure, sinon false.
	 */
	bool majeur( const Date* d );

private:
	char nom[64];
	char prenom[64];
	Date naissance;
};


#endif

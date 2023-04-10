
#ifndef _DATE_H_
#define _DATE_H_


class Date
{
public:
	/**
	 * Constructeur par defaut, initialise les variables a 0.
	 */
	Date( void );
	/**
	 * Destructeur par defaut, sans effet.
	 */
	~Date( void );

	/**
	 * Initialise l'objet avec le jour et le mois donnes
	 * en argument.
	 *
	 * @param j   Jour
	 * @param m   Mois
	 * @param a   Annee
	 */
	void init( int j, int m, int a );
	/**
	 * Determine si la date actuelle est anterieure a celle
	 * donnee en argument.
	 *
	 * @param d   Objet de type Date.
	 *
	 * @return true, la date actuelle est anterieure, sinon false.
	 */
	bool anterieur( const Date* d );
	/**
	 * Compare la date actuelle et celle donnee en argument.
	 *
	 * @param d   Objet de type Date.
	 * @return true, les dates sont identiques, sinon false.
	 */
	bool compare( const Date* d );

public:
	int jour, mois, annee;
};


#endif

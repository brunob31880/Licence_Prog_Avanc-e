
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
	 */
	void init( int j, int m );
	/**
	 * Change la date actuelle pour le lendemain.
	 */
	void lendemain( void );
	/**
	 * Indique si la date actuelle correspond au dernier
	 * jour du mois.
	 *
	 * @return true, dernier jour du mois, sinon false.
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

public:
	int jour, mois;
};


#endif

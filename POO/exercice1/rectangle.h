#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class Rectangle
{
public:
	/**
	 * Constructeur par defaut, initialise la longueur
	 * et la largeur a 0.
	 */
	Rectangle( void );
	/**
	 * Constructeur par valeurs, initialise la longueur
	 * et la largeur avec les valeurs donnees en argument.
	 *
	 * @param lon    Longueur
	 * @param larg   Largeur
	 */
	Rectangle( double lon, double larg );
	/**
	 * Destructeur par defaut, sans effet.
	 */
	~Rectangle( void );
	/**
	 * Initialise la longueur et la largeur a 0.
	 */
	void init( void );
	/**
	 * Calcul le perimetre du rectangle.
	 *
	 * @return Perimetre du rectangle.
	 */
	double perimetre( void );
	/**
	 * Calcul l'air du rectangle.
	 *
	 * @return L'air du rectangle.
	 */
	double air( void );
	/**
	 * Affiche la longueur et la largeur du rectangle.
	 */
	void print( void );

private:
	double longueur, largeur;
};

#endif


#include <iostream>
using namespace std;

#include "rectangle.h"


Rectangle::Rectangle( void )
{
	init();
}

Rectangle::Rectangle( double lon, double larg )
{
	longueur = lon;
	largeur = larg;
}

Rectangle::~Rectangle( void ) { }

void Rectangle::init( void )
{
	longueur = 0;
	largeur = 0;
}

double Rectangle::perimetre( void )
{
	return ( 2 * (longueur + largeur) );
}

double Rectangle::air( void )
{
	return longueur * largeur;
}

void Rectangle::print( void )
{
	cout << "longueur : " << longueur << endl;
	cout << "largeur  : " << largeur << endl;
}

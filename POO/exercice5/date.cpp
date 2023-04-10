
#include <iostream>
using namespace std;

#include "date.h"


Date::Date( int j, int m, int a )
{
	jour = j;
	mois = m;
	annee = a;
}

void Date::affiche( void )
{
	cout << jour << "/" << mois << "/" << annee << endl;
}

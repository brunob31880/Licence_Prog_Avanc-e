
#include <iostream>
using namespace std;

#include "ouvrier.h"
#include "cadre.h"
#include "cadrecom.h"


int main( void )
{
	Employe* emp1 = new Ouvrier( "Michel DUPOND", 2000 );
	Employe* emp2 = new Cadre( "Jean JEAN", 3000, 500 );
	Employe* emp3 = new CadreCom( "Harry GRENAT", 3000, 1000, 500 );

	emp1->presentation();
	cout << endl;
	emp2->presentation();
	cout << endl;
	emp3->presentation();

	delete emp1;
	delete emp2;
	delete emp3;

	return 0;
}

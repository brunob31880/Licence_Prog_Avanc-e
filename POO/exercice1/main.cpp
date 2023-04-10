
#include <iostream>
using namespace std;
#include "rectangle.h"


int main( void )
{
	/* je declare deux variables, r1 et r2 pour tester les deux
	 * constructeurs de rectangle. */
	Rectangle r1, r2( 10, 20 );

	cout << "perimetre r1 : " << r1.perimetre() << endl;
	cout << "air r1 : " << r1.air() << endl;
	r1.print();

	cout << "perimetre r2 : " << r2.perimetre() << endl;
	cout << "air r2 : " << r2.air() << endl;
	r2.print();

	return 0;
}



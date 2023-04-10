# include < stdio .h >

 /**
 * @file
 */

 /**
 * Display the message " Hello World !".
 */
 static void printHelloWorld ( void )
 {
 printf ( " Hello World !\n" ) ;
  }

/**
* Compute the sum of two integers .
*
* @param a First integer .
* @param b Second interger .
*
* @return Sum of a and b.
*/
static int sum ( int a , int b )
{
return a + b ;
}
int main ( void )
{
printHelloWorld () ;
printf ( "9 + 8 : %d\n", sum ( 9 , 8 ) ) ;
}
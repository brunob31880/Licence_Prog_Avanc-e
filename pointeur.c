#include <stdio.h>
#include <stdlib.h>
static void fonction(int *a)
{
    if (NULL != a)
    {
        *a = 0;
    }
}
int main ( int argc , char * argv [])
 {
 int * a = NULL ;
 int b = 2;

 a = & b ;
 fonction ( a ) ;

 printf ("%d %d\n", *a , b ) ;

 return 0;
  }

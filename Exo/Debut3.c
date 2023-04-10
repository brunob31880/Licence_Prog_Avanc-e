#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;
    if (!( a < 0 ? -a : a ) )
     printf ("%d\n", a ) ;
    return 0;
}

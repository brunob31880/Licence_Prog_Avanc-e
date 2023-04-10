#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 96 , b = 96 , c = 78;
    int * p = &a , * q = &b , * r = & c;
    printf("p==q %d\n",(p==q));
    printf("p==r %d\n",(p==r));
    printf("*p==*q %d\n",(*p==*q));
    printf("*p==*r %d\n",(*p==*r));
    return 0;
}


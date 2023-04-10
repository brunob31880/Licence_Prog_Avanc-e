#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *p, *q;

    while (1)
    {
        q = (int)malloc(1 * sizeof(int));
        *q = 0;
        p = (int)malloc(1 * sizeof(int));
        p = q;
        free(p);
    }

    return 0;
}
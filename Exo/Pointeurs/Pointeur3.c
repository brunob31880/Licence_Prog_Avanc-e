#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
static void f(int *p1, int *p2, int *p3)
{
    p1 = p2;
    *p2 = *p3;
    *p3 = 8;
}

static void g(int **p1, int **p2, int **p3)
{
    *p1 = *p2;
    **p2 = **p3;
    **p3 = 12;
}

int main(void)
{
    int *a = NULL, *b = NULL, *c = NULL;
    a = (int *)malloc(1 * sizeof(int));
    b = (int *)malloc(1 * sizeof(int));
    c = (int *)malloc(1 * sizeof(int));

    *a = 1;
    *b = 2;
    *c = 3;

    f(a, b, c);
    printf("%d %d %d\n", *a, *b, *c);
    g(&a, &b, &c);
    printf("%d %d %d\n", *a, *b, *c);

    free(a);
    free(b);
    free(c);

    return 0;
}
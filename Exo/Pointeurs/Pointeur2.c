#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int a = 1;
    int b[2] = {3, 4};
    int *p1 = NULL, *p2 = NULL;

    p1 = &a;
    p2 = b;

    printf("%d %d %d\n", a, *p1, *p2);
    *p1 = *p2 + 1;
    printf("%d %d %d\n", a, *p1, *p2);
    p1 = p2;
    printf("%d %d %d\n", a, *p1, *p2);
    *p1 = *p1 - *p2;
    printf("%d %d %d\n", a, *p1, *p2);
    *p2 = *(p2 + 1);
    printf("%d %d %d\n", a, *p1, *p2);
    a = *p2 * *p1;
    printf("%d %d %d\n", a, *p1, *p2);
    p1 = &a;
    printf("%d %d %d\n", a, *p1, *p2);
    *p2 = *p1;
    printf("%d %d %d\n", a, *p1, *p2);

    return 0;
}

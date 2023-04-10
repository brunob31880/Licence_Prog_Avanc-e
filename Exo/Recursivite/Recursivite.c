#include <stdio.h>
#include <stdlib.h>

static int mystere(int a, int b)
{
    if (0 == a)
    {
        return b;
    }
    if (0 == b)
    {
        return a;
    }
    if (b>0 && a>0)  return mystere(a + 1, b - 1);
    else if (b<0 && a>0)  return mystere(a - 1, b + 1);
    else if (b>0 && a<0)  return mystere(a + 1, b - 1);
    else return mystere(a - 1, b + 1);
}

int main()
{
    int ret=mystere(-10,-11);
    printf("Mystere=%d\n",ret);
    return 0;
}

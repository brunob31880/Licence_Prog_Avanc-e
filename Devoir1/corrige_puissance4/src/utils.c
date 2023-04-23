#include <stdio.h>
#include "utils.h"

int getIntValue(void)
{
    int value = 0;
    while (1 != scanf("%d", &value))
    {
        printf("valeur incorrecte, recommencez \n");
        getchar();
    }

    return value;
}
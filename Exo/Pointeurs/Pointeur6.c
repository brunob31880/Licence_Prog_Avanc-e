#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char *mot;
    printf("Longeur du mot\n");
    int l;
    scanf("%d", &l);
    printf("Longueur=%d\n", l);
    mot = (char *)malloc((l + 1) * sizeof(char));
    char c;
    for (int i = 0; i < l; i++)
    {

        printf("Entrez caractère\n");
        scanf(" %c", &c);
        *(mot + i) = c;
    }
    printf("La chaine est %s\n", mot);
}

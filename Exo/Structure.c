#include <stdio.h>
#include <stdlib.h>
struct rectangle{
        float longueur;
        float largeur;
} ;
    
float perimetre(struct rectangle rect) {
  return rect.longueur+rect.largeur;
}
float aire(struct rectangle rect) {
  return rect.longueur*rect.largeur;
}
void initrect(float longu,float larg,struct rectangle *r1){
    r1->longueur=longu;
    r1->largeur=larg;
}
int main()
{
    struct rectangle rect={10,10};
    initrect(20,10,&rect);
    printf("Perimetre %f\n",perimetre(rect));
    printf("Aire %f\n",aire(rect));
    return 0;
}

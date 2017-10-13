#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"
#include "tp3.c"

int main()
{
    T_Liste* liste =creerListe();
    if (liste->taille==0) printf("la liste est vide \n");
    insererElement(liste, "test");
    afficher_Liste(liste);
    insererElement(liste, "zorro");
    afficher_Liste(liste);
    insererElement(liste, "abracadabra");
    afficher_Liste(liste);
    insererElement(liste, "beta");
    afficher_Liste(liste);
    insererElement(liste, "mamamia");
    afficher_Liste(liste);
    return 0;
}

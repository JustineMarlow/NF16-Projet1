#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

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

    T_Element * a_trouver = rechercherElement(liste, "zorro");
    afficher_Element(a_trouver);

    int res = supprimerElement(liste, "beta");
    if (res == 0 ) printf("Suppression reussie \n");
    else printf("echec de suppression \n");
    afficher_Liste(liste);

    res = supprimerElement(liste, "zorro");
    if (res == 0 ) printf("Suppression reussie \n");
    else printf("echec de suppression \n");
    afficher_Liste(liste);

    res = supprimerElement(liste, "abracadabra");
    if (res == 0 ) printf("Suppression reussie \n");
    else printf("echec de suppression \n");
    afficher_Liste(liste);

    return 0;
}

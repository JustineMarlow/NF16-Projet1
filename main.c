#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

int main()
{
    T_Liste* liste =creerListe();
    if (liste->taille==0) printf("la liste est vide \n");
    insererElement(liste, "test");
    insererElement(liste, "zorro");
    insererElement(liste, "abracadabra");
    insererElement(liste, "beta");
    insererElement(liste, "mamamia");

    T_Element * a_trouver = rechercherElement(liste, "zorro");

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

    res = supprimerElement(liste, "mamamia");
    if (res == 0 ) printf("Suppression reussie \n");
    else printf("echec de suppression \n");
    afficher_Liste(liste);

    res = supprimerElement(liste, "test");
    if (res == 0 ) printf("Suppression reussie \n");
    else printf("echec de suppression \n");
    afficher_Liste(liste);

    insererElement(liste, "test");
    insererElement(liste, "zorro");
    insererElement(liste, "abracadabra");
    insererElement(liste, "beta");
    insererElement(liste, "mamamia");

    supprimerListe(liste);
    afficher_Liste(liste);

    return 0;
}

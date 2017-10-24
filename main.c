#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

int main()
{
    T_Liste* liste1 =creerListe();
    insererElement(liste1, "test");
    insererElement(liste1, "mamamia");
    afficher_Liste(liste1);
    afficher_Element(rechercherElement(liste1,"test"));

    T_Liste* liste2 =creerListe();
    insererElement(liste2, "abracadabra");
    insererElement(liste2, "zorro");
    insererElement(liste2, "beta");
    afficher_Liste(liste2);
    int res=supprimerElement(liste2,"beta");
    afficher_Liste(liste2);

    T_Liste* liste3 =fusionnerListes(liste1,liste2);
    afficher_Liste(liste3);
    supprimerListe(liste3);
    afficher_Liste(liste3);

    return 0;
}

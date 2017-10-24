#include <stdio.h>
#include <stdlib.h>
#include "tp3.h"

int main()
{
    unsigned int i=0; //nombre de listes créées
    unsigned int k,k1,k2;
    T_Liste* tab[5];
    char valeur[20];
    int res;
    T_Element* a_trouver=NULL;

    int menu;
    do
    {
    printf("\n Menu \n");
    printf("1. Créer une liste \n");
    printf("2. Ajouter un élément dans une liste \n");
    printf("3. Supprimer un élément d'une liste \n");
    printf("4. Rechercher un élément dans une liste \n");
    printf("5. Afficher les éléments d'une liste \n");
    printf("6. Supprimer une liste \n");
    printf("7. Fusionner deux listes \n");
    printf("8. Quitter \n");
    scanf("%d",&menu);

    switch (menu) {
        case 1: //Créer une liste
            if(i==5) printf("Impossible de créer une nouvelle liste \n");
            else {
                tab[i] = creerListe();
                printf("Vous avez créé une liste numéro %d \n",i+1);
                i++;
            }
            break;
        case 2: //Ajouter un élément dans une liste
            printf("Entrez le numéro de la liste \n");
            scanf("%d",&k);
            if (k>i+1) printf("Erreur, cette liste n'existe pas \n");
            else {
                printf("Entrez la chaîne de caractère à ajouter \n");
                scanf("%s",&valeur);
                insererElement(tab[k-1],valeur);
            }
            break;
        case 3: //Supprimer un élément d'une liste
            printf("Entrez le numéro de la liste \n");
            scanf("%d",&k);
            if (k>i+1) printf("Erreur, cette liste n'existe pas \n");
            else {
                printf("Entrez la chaîne de caractère à supprimer \n");
                scanf("%s",&valeur);
                res=supprimerElement(tab[k-1],valeur);
                if (res==0) printf("Element supprimé \n");
                else printf("Problème dans la suppression \n");
            }
            break;
        case 4: //Rechercher un élément dans une liste
            printf("Entrez le numéro de la liste \n");
            scanf("%d",&k);
            if (k>i+1) printf("Erreur, cette liste n'existe pas \n");
            else {
                printf("Entrez la chaîne de caractère à rechercher \n");
                scanf("%s",&valeur);
                a_trouver=rechercherElement(tab[k-1],valeur);
                if (a_trouver!=NULL) printf("Element trouvé \n");
                else printf("Problème dans la recherche \n");
                a_trouver=NULL;
            }
            break;
        case 5: //Afficher les éléments d'une liste
            printf("Entrez le numéro de la liste à afficher \n");
            scanf("%d",&k);
            if (k>i+1) printf("Erreur, cette liste n'existe pas \n");
            else afficher_Liste(tab[k-1]);
            break;
        case 6: //Supprimer une liste
            printf("Entrez le numéro de la liste à supprimer \n");
            scanf("%d",&k);
            if (k>i+1) printf("Erreur, cette liste n'existe pas \n");
            else supprimerListe(tab[k-1]);
            break;
        case 7:
            if(i==5) printf("Impossible de créer une nouvelle liste pour la fusion \n");
            else {
            printf("Entrez le numéro de la 1ere liste à fusionner \n");
            scanf("%d",&k1);
            if (k1>i+1) printf("Erreur, cette liste n'existe pas \n");
            else {
                    printf("Entrez le numéro de la 2eme liste à fusionner \n");
                    scanf("%d",&k2);
                    if (k2>i+1) printf("Erreur, cette liste n'existe pas \n");
                    else {
                            tab[i]=fusionnerListes(tab[k1-1],tab[k2-1]);
                            printf("La liste %d est la fusion de la liste %d et de la liste %d \n",i+1,k1,k2);
                            i++;
                        }
                }
            }
            break;
        case 8: //Quitter
            printf("A bientot");
            break;
        default : printf("Erreur, veuillez recommencer \n");
    }
    }
    while(menu!=8);
    return 0;
}

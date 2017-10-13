#include "tp3.h"

T_Element *creerElement (char *val) {
    T_Element* newElement=malloc(sizeof(T_Element));
    strcpy(newElement->valeur,val);
    newElement->suivant=NULL;
    newElement->precedent=NULL;
    return newElement;
};

T_Liste *creerListe () {
    T_Liste* newListe=malloc(sizeof(T_Liste));
    newListe->taille=0;
    newListe->tete=NULL;
    newListe->queue=NULL;
    return newListe;
};

void afficher_Liste(T_Liste * liste) {
    unsigned int i;
    T_Element* curseur=malloc(sizeof(T_Element));
    curseur=liste->tete;
    printf("taille : %d \n", liste->taille);
    for (i=0; i<liste->taille; i++){
        printf("%s \n",curseur->valeur);
        curseur=curseur->suivant;
    }
    printf("\n");
}

void afficher_Element(T_Element * element) {
    if (element!=NULL) printf("%s \n", element->valeur);
}

int insererElement(T_Liste *list, char *val){
    T_Element *nouveau = creerElement(val);
    strcpy(nouveau->valeur,val);
    //si la liste est vide
    if(list->taille == 0){
        list->queue = nouveau;
        list->tete = nouveau;
        list->taille++;
        return 0;
    }
    //sinon, recherche de l'endroit où il faut insérer
    T_Element *curseur = malloc(sizeof(T_Element));
    curseur = list->tete;
    while(curseur->suivant != NULL && strcmp(curseur->valeur,val)<0) curseur = curseur->suivant;
    if(strcmp(curseur->valeur,val) == 0) return -1; //échec car existe déjà

    //insertion en tete
    if(curseur == list->tete && strcmp(curseur->valeur,val)>0){
        nouveau->suivant = curseur;
        curseur->precedent = nouveau;
        list->taille++;
        list->tete = nouveau;
        return 0;
    }
    //insertion en queue
    if (curseur==list->queue && strcmp(curseur->valeur,val)<0) {
        nouveau->precedent = curseur;
        curseur->suivant = nouveau;
        list->taille++;
        list->queue = nouveau;
        return 0;
    }
    //insertion ailleurs
    nouveau->suivant = curseur;
    nouveau->precedent = curseur->precedent;
    curseur->precedent->suivant=nouveau;
    curseur->precedent=nouveau;
    list->taille++;
    return 0;
}

T_Element *rechercherElement(T_Liste *list, char *val){

    if(list->taille == 0) return NULL;
    T_Element *curseur = malloc(sizeof(T_Element));
    curseur = list->tete;
    while(curseur != NULL && strcasecmp(curseur->valeur,val)<0) curseur = curseur->suivant;
    return curseur;
}

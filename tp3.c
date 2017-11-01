#include "tp3.h"

T_Element *creerElement (char *val) {
    T_Element* newElement=malloc(sizeof(T_Element));
    if(newElement == NULL){
        printf("Allocation impossible ! \n");
        return NULL;
    }
    strcpy(newElement->valeur,val);
    newElement->suivant=NULL;
    newElement->precedent=NULL;
    return newElement;
};

T_Liste *creerListe () {
    T_Liste* newListe=malloc(sizeof(T_Liste));
    if(newListe == NULL){
        printf("Allocation impossible ! \n");
        return NULL;
    }
    newListe->taille=0;
    newListe->tete=NULL;
    newListe->queue=NULL;
    return newListe;
};


void afficher_Liste(T_Liste * liste) {
    unsigned int i;
    T_Element* curseur=liste->tete;
    printf("taille : %d \n", liste->taille);
    for (i=0; i<liste->taille; i++){
        afficher_Element(curseur);
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
    //sinon, recherche de l'endroit ou il faut inserer
    T_Element *curseur = list->tete;
    while(curseur->suivant != NULL && strcmp(curseur->valeur,val)<0) curseur = curseur->suivant;
    if(strcmp(curseur->valeur,val) == 0) {//free(curseur);
    return -1; } //echec car existe deja¡

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

T_Element *rechercherElement(T_Liste* list, char *val){

    if(list->taille == 0) return NULL;
    T_Element *curseur = list->tete;
    while(curseur != NULL && strcasecmp(curseur->valeur,val)<0) curseur = curseur->suivant;
    return curseur;
}

int supprimerElement(T_Liste* list, char* val){

    if (list->taille==0) return -1; //liste vide
    T_Element* curseur = rechercherElement(list, val);
    if (curseur==NULL) return -1; //element pas dans la liste
    if (curseur==list->tete && curseur==list->queue){
        list->tete=NULL;
        list->queue=NULL;
        free(curseur);
        list->taille--;
        return 0;
    }
    if (curseur==list->tete){
        curseur->suivant->precedent=NULL;
        list->tete=curseur->suivant;
        free(curseur);
        list->taille--;
        return 0;
    }
    if (curseur==list->queue){
        curseur->precedent->suivant=NULL;
        list->queue=curseur->precedent;
        free(curseur);
        list->taille--;
        return 0;

    }
    curseur->precedent->suivant=curseur->suivant;
    curseur->suivant->precedent=curseur->precedent;
    free(curseur);
    list->taille--;
    return 0;
};

int supprimerListe(T_Liste* list){
    if(list->tete!=NULL)
    {
    T_Element *curseur = list->tete;
    T_Element *tmp;
    while(curseur->suivant != NULL){
        tmp = curseur->suivant;
        free(curseur);
        curseur = tmp;
    }
    }
    free(list);
    //T_Liste* nouvelle = creerListe ();
    //int res=insererElement(nouvelle, "haha");
    return 0;
};

void ajout_queue(T_Liste* list, char* val){
    T_Element* nouveau = creerElement(val);
    if (list->taille==0) {
        list->tete=nouveau;
        list->queue=nouveau;
        list->taille++;}
    else {
        list->queue->suivant=nouveau;
        nouveau->precedent=list->queue;
        list->taille++;
        list->queue=nouveau;
    };
};

T_Liste *fusionnerListes(T_Liste *list1, T_Liste *list2){
    T_Liste* fusion=creerListe();
    T_Element* curseur1=list1->tete;
    T_Element* curseur2=list2->tete;

    while(curseur1!=NULL || curseur2!=NULL){
        if (curseur1==NULL || (curseur2!=NULL && strcmp(curseur1->valeur,curseur2->valeur)>=0)){
            ajout_queue(fusion,curseur2->valeur);
            curseur2=curseur2->suivant;
        }
        else {
                if (curseur2==NULL || (curseur1!=NULL && strcmp(curseur1->valeur,curseur2->valeur)<0)){
                    ajout_queue(fusion,curseur1->valeur);
                    curseur1=curseur1->suivant;
                }
        }
    }
    return fusion;
};


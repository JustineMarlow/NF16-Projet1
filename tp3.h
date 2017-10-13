#ifndef TP3_H_INCLUDED
#define TP3_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element {
    char valeur[20];
    struct Element* suivant;
    struct Element* precedent;
} T_Element;

typedef struct Liste {
    int taille;
    struct Element* tete;
    struct Element* queue;
} T_Liste;

T_Element *creerElement (char *val);

T_Liste *creerListe ();

void afficher_Liste(T_Liste * liste);

#endif
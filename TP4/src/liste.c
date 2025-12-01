#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

// Initialise la liste chaînée
void init_liste(struct liste_couleurs *liste) {
    liste->tete = NULL;
}

// Insère une nouvelle couleur en tête de liste
void insertion(const struct couleur *couleur_ptr, struct liste_couleurs *liste) {
    struct maillon *nouveau_maillon = (struct maillon *)malloc(sizeof(struct maillon));

    if (nouveau_maillon == NULL) {
        perror("Erreur d'allocation memoire pour l'insertion");
        return;
    }

    nouveau_maillon->data = *couleur_ptr;
    nouveau_maillon->suivant = liste->tete;
    liste->tete = nouveau_maillon;
}

// Parcours et affiche toutes les couleurs de la liste
void parcours(const struct liste_couleurs *liste) {
    struct maillon *courant = liste->tete;
    int index = 1;

    if (courant == NULL) {
        printf("La liste est vide.\n");
        return;
    }

    while (courant != NULL) {
        printf("Couleur %2d: R=0x%02X, G=0x%02X, B=0x%02X, A=0x%02X\n",
               index++,
               courant->data.R,
               courant->data.G,
               courant->data.B,
               courant->data.A);
        
        courant = courant->suivant;
    }
}

// Fonction de nettoyage (pour éviter les fuites mémoire)
void liberer_liste(struct liste_couleurs *liste) {
    struct maillon *courant = liste->tete;
    struct maillon *suivant;

    while (courant != NULL) {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
    liste->tete = NULL;
}

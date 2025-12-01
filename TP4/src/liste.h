#ifndef LISTE_H
#define LISTE_H

#include <stddef.h> // Pour NULL

// Structure pour un nœud de la liste (une couleur RGBA)
struct couleur {
    unsigned char R, G, B, A;
};

// Structure d'un maillon de la liste chaînée
struct maillon {
    struct couleur data;
    struct maillon *suivant;
};

// Structure principale de la liste (contient la tête)
struct liste_couleurs {
    struct maillon *tete;
};

// Prototypes des fonctions de gestion de liste
void init_liste(struct liste_couleurs *liste);
void insertion(const struct couleur *couleur_ptr, struct liste_couleurs *liste);
void parcours(const struct liste_couleurs *liste);
void liberer_liste(struct liste_couleurs *liste); // Fonction de nettoyage

#endif // LISTE_H

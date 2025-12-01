#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> // Nécessaire pour le type booléen

#define TAILLE_MAX 100
#define VAL_MAX_COMPOSANT 255 // Valeur maximale pour un octet

// =================================================================
// 1. Définition des structures
// =================================================================

// Structure pour représenter une couleur (RGBA)
struct Couleur {
    unsigned char R; // Rouge (0-255)
    unsigned char G; // Vert (0-255)
    unsigned char B; // Bleu (0-255)
    unsigned char A; // Alpha (0-255)
};

// Structure pour stocker les couleurs distinctes et leur compteur
struct OccurenceCouleur {
    struct Couleur c; // La couleur elle-même
    int compteur;     // Son nombre d'occurrences
};

// =================================================================
// Déclarations des fonctions
// =================================================================

void remplir_tableau_couleurs(struct Couleur tab[], int taille);
bool comparer_couleurs(struct Couleur c1, struct Couleur c2);
void afficher_couleur(struct Couleur c);

int main() {
    // Tableau des 100 couleurs originales
    struct Couleur couleurs_originales[TAILLE_MAX];
    
    // Tableau pour stocker les couleurs distinctes et leurs comptes
    // La taille maximale est la taille du tableau original (100)
    struct OccurenceCouleur couleurs_distinctes[TAILLE_MAX];
    
    int nb_couleurs_distinctes = 0; // Compteur des couleurs distinctes trouvées
    int i, j; // Compteurs de boucle

    srand(time(NULL));

    printf("--- Compteur d'Occurrences de Couleurs Distinctes ---\n");
    
    // Remplissage du tableau initial avec des couleurs aléatoires
    remplir_tableau_couleurs(couleurs_originales, TAILLE_MAX);
    
    // =================================================================
    // 3. Algorithme de Comptage
    // =================================================================
    
    // Parcourir le tableau de couleurs originales
    for (i = 0; i < TAILLE_MAX; i++) {
        struct Couleur couleur_courante = couleurs_originales[i];
        int index_trouve = -1;

        // A. Recherche : Vérifier si la couleur existe déjà dans le tableau des distinctes
        for (j = 0; j < nb_couleurs_distinctes; j++) {
            if (comparer_couleurs(couleur_courante, couleurs_distinctes[j].c)) {
                index_trouve = j;
                break; // Couleur trouvée, on arrête la recherche
            }
        }

        // B. Mise à jour du compteur
        if (index_trouve != -1) {
            // Couleur déjà vue : incrémenter le compteur
            couleurs_distinctes[index_trouve].compteur++;
        } else {
            // Nouvelle couleur : l'ajouter au tableau des distinctes
            if (nb_couleurs_distinctes < TAILLE_MAX) {
                couleurs_distinctes[nb_couleurs_distinctes].c = couleur_courante;
                couleurs_distinctes[nb_couleurs_distinctes].compteur = 1;
                nb_couleurs_distinctes++; // Incrémenter le nombre total de couleurs distinctes
            }
            // Note: Une gestion d'erreur serait nécessaire si nb_couleurs_distinctes atteignait TAILLE_MAX
        }
    }

    // =================================================================
    // 4. Affichage du résultat
    // =================================================================
    printf("\nTotal de couleurs initiales : %d\n", TAILLE_MAX);
    printf("Nombre de couleurs distinctes trouvées : %d\n\n", nb_couleurs_distinctes);
    printf("--- Couleurs distinctes et leur nombre d'occurrences ---\n");

    for (i = 0; i < nb_couleurs_distinctes; i++) {
        // Affichage de la couleur (R G B A)
        afficher_couleur(couleurs_distinctes[i].c);
        
        // Affichage du compteur
        printf(": %d\n", couleurs_distinctes[i].compteur);
    }

    printf("----------------------------------------------------------\n");

    return 0;
}

// =================================================================
// Implémentation des fonctions
// =================================================================

/**
 * Remplit le tableau avec des couleurs aléatoires.
 */
void remplir_tableau_couleurs(struct Couleur tab[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        tab[i].R = (unsigned char)(rand() % (VAL_MAX_COMPOSANT + 1));
        tab[i].G = (unsigned char)(rand() % (VAL_MAX_COMPOSANT + 1));
        tab[i].B = (unsigned char)(rand() % (VAL_MAX_COMPOSANT + 1));
        tab[i].A = (unsigned char)(rand() % (VAL_MAX_COMPOSANT + 1));
    }
}

/**
 * Compare deux structures Couleur et retourne true si elles sont identiques.
 */
bool comparer_couleurs(struct Couleur c1, struct Couleur c2) {
    // Les couleurs sont identiques si tous les composants (R, G, B, A) correspondent
    return (c1.R == c2.R &&
            c1.G == c2.G &&
            c1.B == c2.B &&
            c1.A == c2.A);
}

/**
 * Affiche une couleur au format hexadécimal (comme dans l'exemple).
 */
void afficher_couleur(struct Couleur c) {
    // Utiliser %02X pour afficher l'unsigned char en hexadécimal sur deux chiffres (avec zéro initial)
    printf("0x%02X 0x%02X 0x%02X 0x%02X", c.R, c.G, c.B, c.A);
}

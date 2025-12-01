#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

#define TAILLE_MAX 100
// Nouvelle plage réduite pour garantir des répétitions (0 à 3)
#define VAL_REPETITION_MAX 3 

// =================================================================
// 1. Définition des structures
// =================================================================

// Structure pour représenter une couleur (RGBA)
struct Couleur {
    unsigned char R; 
    unsigned char G; 
    unsigned char B; 
    unsigned char A; 
};

// Structure pour stocker les couleurs distinctes et leur compteur
struct OccurenceCouleur {
    struct Couleur c; 
    int compteur;     
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
    struct OccurenceCouleur couleurs_distinctes[TAILLE_MAX];
    
    int nb_couleurs_distinctes = 0; 
    int i, j; 

    // Initialisation du générateur aléatoire (une seule fois)
    srand(time(NULL));

    printf("--- Compteur d'Occurrences de Couleurs Distinctes ---\n");
    printf("> Les composants de couleur sont limités à la plage [0, %d] pour forcer des répétitions.\n\n", VAL_REPETITION_MAX);
    
    // Remplissage du tableau initial avec des couleurs aléatoires et répétées
    remplir_tableau_couleurs(couleurs_originales, TAILLE_MAX);
    
    // =================================================================
    // 2. Algorithme de Comptage (Recherche Linéaire pour les distinctes)
    // =================================================================
    
    for (i = 0; i < TAILLE_MAX; i++) {
        struct Couleur couleur_courante = couleurs_originales[i];
        int index_trouve = -1;

        // Recherche : Vérifier si la couleur existe déjà
        for (j = 0; j < nb_couleurs_distinctes; j++) {
            if (comparer_couleurs(couleur_courante, couleurs_distinctes[j].c)) {
                index_trouve = j;
                break; 
            }
        }

        // Mise à jour du compteur ou ajout
        if (index_trouve != -1) {
            couleurs_distinctes[index_trouve].compteur++;
        } else {
            // Nouvelle couleur : l'ajouter
            if (nb_couleurs_distinctes < TAILLE_MAX) {
                couleurs_distinctes[nb_couleurs_distinctes].c = couleur_courante;
                couleurs_distinctes[nb_couleurs_distinctes].compteur = 1;
                nb_couleurs_distinctes++; 
            }
        }
    }

    // =================================================================
    // 3. Affichage du résultat
    // =================================================================
    printf("Total de couleurs initiales : %d\n", TAILLE_MAX);
    printf("Nombre de couleurs distinctes trouvées : %d\n\n", nb_couleurs_distinctes);
    printf("--- Couleurs distinctes et leur nombre d'occurrences ---\n");

    for (i = 0; i < nb_couleurs_distinctes; i++) {
        // Affichage de la couleur (R G B A) en hexadécimal
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
 * Remplit le tableau avec des couleurs aléatoires dans une plage réduite.
 * MODIFIÉ pour utiliser VAL_REPETITION_MAX.
 */
void remplir_tableau_couleurs(struct Couleur tab[], int taille) {
    int i;
    int max = VAL_REPETITION_MAX; // Limite supérieure pour rand()
    for (i = 0; i < taille; i++) {
        tab[i].R = (unsigned char)(rand() % (max + 1));
        tab[i].G = (unsigned char)(rand() % (max + 1));
        tab[i].B = (unsigned char)(rand() % (max + 1));
        tab[i].A = (unsigned char)(rand() % (max + 1));
    }
}

/**
 * Compare deux structures Couleur et retourne true si elles sont identiques.
 */
bool comparer_couleurs(struct Couleur c1, struct Couleur c2) {
    return (c1.R == c2.R &&
            c1.G == c2.G &&
            c1.B == c2.B &&
            c1.A == c2.A);
}

/**
 * Affiche une couleur au format hexadécimal.
 */
void afficher_couleur(struct Couleur c) {
    // %02X affiche l'unsigned char en hexadécimal sur deux chiffres
    printf("0x%02X 0x%02X 0x%02X 0x%02X", c.R, c.G, c.B, c.A);
}

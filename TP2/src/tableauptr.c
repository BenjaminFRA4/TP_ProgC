#include <stdio.h>
#include <stdlib.h> // Pour rand() et srand()
#include <time.h>   // Pour time()

#define TAILLE 11 // Taille des tableaux (selon l'exemple)

// Déclaration de la fonction d'affichage
void afficher_tableau_entiers(const int *tab, int taille, const char *titre);
void afficher_tableau_flottants(const float *tab, int taille, const char *titre);

int main() {
    // 1. Déclaration des tableaux
    int tab_entiers[TAILLE];
    float tab_flottants[TAILLE];
    
    // Initialisation de la graine du générateur aléatoire
    srand(time(NULL)); 
    
    int i; // Compteur pour les boucles
    
    // Pointeur pour le tableau d'entiers
    int *ptr_int = tab_entiers; 
    
    // Pointeur pour le tableau de flottants
    float *ptr_float = tab_flottants; 

    // =================================================================
    // 2. Remplissage des tableaux avec des valeurs aléatoires
    // Nous utilisons la notation indicielle ici, car le remplissage n'est pas le focus principal.
    // L'exercice demande de ne pas utiliser la notation indicielle pour le PARCOURS de MODIFICATION.
    // =================================================================
    for (i = 0; i < TAILLE; i++) {
        // Entiers: valeurs aléatoires entre 10 et 150
        tab_entiers[i] = (rand() % 141) + 10; 
        // Flottants: valeurs aléatoires entre 0.00 et 9.99
        tab_flottants[i] = (float)(rand() % 1000) / 100.0f;
    }

    // Affichage AVANT manipulation
    afficher_tableau_entiers(tab_entiers, TAILLE, "Tableau d'entiers (avant la multiplication par 3)");
    afficher_tableau_flottants(tab_flottants, TAILLE, "Tableau de nombres à virgule flottante (avant la multiplication par 3)");

    // =================================================================
    // 3. Parcours et Multiplication par 3 (UTILISATION EXCLUSIVE DE POINTEURS)
    // =================================================================
    printf("\n--- Modification des éléments dont l'indice est divisible par 2 (0, 2, 4, ...) ---\n");
    
    for (i = 0; i < TAILLE; i++) {
        if (i % 2 == 0) {
            // Modification du tableau d'entiers
            // *(ptr_int + i) est équivalent à tab_entiers[i]
            *(ptr_int + i) *= 3; 

            // Modification du tableau de flottants
            // *(ptr_float + i) est équivalent à tab_flottants[i]
            *(ptr_float + i) *= 3.0f; 
        }
    }

    // Affichage APRÈS manipulation
    afficher_tableau_entiers(tab_entiers, TAILLE, "\nTableau d'entiers (après la multiplication par 3)");
    afficher_tableau_flottants(tab_flottants, TAILLE, "Tableau de nombres à virgule flottante (après la multiplication par 3)");
    
    return 0;
}

// =================================================================
// Fonctions d'Affichage (avec pointeurs)
// =================================================================

/**
 * Affiche les éléments d'un tableau d'entiers en utilisant l'arithmétique des pointeurs.
 */
void afficher_tableau_entiers(const int *tab, int taille, const char *titre) {
    printf("\n%s :\n", titre);
    printf("  ");
    int i;
    for (i = 0; i < taille; i++) {
        // Utilisation de la notation par pointeur pour accéder à l'élément
        printf("%d", *(tab + i)); 
        if (i < taille - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

/**
 * Affiche les éléments d'un tableau de flottants en utilisant l'arithmétique des pointeurs.
 */
void afficher_tableau_flottants(const float *tab, int taille, const char *titre) {
    printf("\n%s :\n", titre);
    printf("  ");
    int i;
    for (i = 0; i < taille; i++) {
        // Utilisation de la notation par pointeur pour accéder à l'élément
        printf("%.2f", *(tab + i)); 
        if (i < taille - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

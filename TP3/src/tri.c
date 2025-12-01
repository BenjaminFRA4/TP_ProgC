#include <stdio.h>
#include <stdlib.h> // Pour rand() et srand()
#include <time.h>   // Pour time()

#define TAILLE 100 // Taille du tableau

// Déclaration des fonctions
void remplir_tableau(int tab[], int taille);
void afficher_tableau(const int tab[], int taille, const char *titre);
void tri_a_bulles(int tab[], int taille);

int main() {
    int tableau[TAILLE];

    // Initialisation de la graine pour le générateur aléatoire
    srand(time(NULL)); 

    printf("--- Tri Croissant d'un Tableau de %d Entiers ---\n", TAILLE);

    // 1. Remplissage et affichage initial
    remplir_tableau(tableau, TAILLE);
    afficher_tableau(tableau, TAILLE, "Tableau non trié");

    // 2. Tri du tableau
    tri_a_bulles(tableau, TAILLE);

    // 3. Affichage du tableau trié
    afficher_tableau(tableau, TAILLE, "Tableau trié par ordre croissant");
    
    printf("\n--- Tri terminé ---\n");

    return 0;
}

// =================================================================
// FONCTIONS UTILITAIRES
// =================================================================

/**
 * Remplit le tableau avec des entiers aléatoires entre -500 et 500.
 */
void remplir_tableau(int tab[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        // Génère une valeur entre -500 et 500
        tab[i] = (rand() % 1001) - 500; 
    }
}

/**
 * Affiche le contenu du tableau.
 */
void afficher_tableau(const int tab[], int taille, const char *titre) {
    printf("\n%s :\n", titre);
    int i;
    int max_affichage = (taille > 20) ? 20 : taille; // Afficher max 20 éléments pour la lisibilité
    
    printf("  ");
    for (i = 0; i < max_affichage; i++) {
        printf("%d ", tab[i]);
    }
    if (taille > max_affichage) {
        printf("... (%d entiers au total)", taille);
    }
    printf("\n");
}

/**
 * Implémentation de l'algorithme de Tri à Bulles (Bubble Sort).
 * Tri le tableau par ordre croissant.
 */
void tri_a_bulles(int tab[], int taille) {
    int i, j;
    int temp; // Variable temporaire pour l'échange (swap)
    
    // Boucle externe : pour le nombre de passes nécessaires
    for (i = 0; i < taille - 1; i++) {
        
        // Boucle interne : pour parcourir les éléments non triés
        // À chaque passe 'i', le plus grand élément restant est placé à la fin (taille - 1 - i)
        for (j = 0; j < taille - 1 - i; j++) {
            
            // Si l'élément courant est plus grand que le suivant
            if (tab[j] > tab[j + 1]) {
                // Échange (Swap) des deux éléments
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

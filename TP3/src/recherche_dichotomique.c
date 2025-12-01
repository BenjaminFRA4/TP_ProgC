#include <stdio.h>
#include <stdlib.h> // Pour rand() et srand()
#include <time.h>   // Pour time()

#define TAILLE 100 // Taille du tableau

// Déclaration de la fonction d'affichage
void afficher_tableau(const int tab[], int taille, const char *titre);

int main() {
    int tableau[TAILLE];
    int i; 
    int entier_cherche;
    // Utiliser un drapeau (flag) pour indiquer si l'élément a été trouvé
    int trouve = 0; 

    // Initialisation de la graine pour le générateur de nombres aléatoires
    srand(time(NULL)); 

    printf("--- Recherche Linéaire d'un Entier dans un Tableau ---\n");
    
    // =================================================================
    // 1. Remplissage du tableau avec des valeurs aléatoires
    // =================================================================
    for (i = 0; i < TAILLE; i++) {
        // Valeurs aléatoires entre -50 et 50
        tableau[i] = (rand() % 101) - 50; 
    }

    // Affichage du tableau initial
    afficher_tableau(tableau, TAILLE, "Tableau généré (affichage des 20 premiers éléments)");

    // =================================================================
    // 2. Demande de l'entier à chercher
    // =================================================================
    printf("\nEntrez l'entier que vous souhaitez chercher : ");
    // Vérifier la saisie
    if (scanf("%d", &entier_cherche) != 1) {
        fprintf(stderr, "Erreur de saisie. Veuillez entrer un nombre entier.\n");
        return 1;
    }

    // =================================================================
    // 3. Logique de Recherche Linéaire
    // =================================================================
    for (i = 0; i < TAILLE; i++) {
        // Si l'élément courant correspond à l'entier recherché
        if (tableau[i] == entier_cherche) {
            trouve = 1; // Marquer le drapeau comme trouvé
            break;      // Sortir immédiatement de la boucle pour optimiser
        }
    }

    // =================================================================
    // 4. Affichage du résultat
    // =================================================================
    printf("\nRésultat : ");
    if (trouve) {
        printf("entier présent\n");
    } else {
        printf("entier absent\n");
    }
    
    printf("\n--- Recherche terminée ---\n");

    return 0;
}

/**
 * Affiche le contenu du tableau.
 */
void afficher_tableau(const int tab[], int taille, const char *titre) {
    printf("\n%s :\n", titre);
    int i;
    // Limiter l'affichage pour la lisibilité
    int max_affichage = (taille > 20) ? 20 : taille; 
    
    printf("  ");
    for (i = 0; i < max_affichage; i++) {
        printf("%d ", tab[i]);
    }
    if (taille > max_affichage) {
        printf("... (%d entiers au total)", taille);
    }
    printf("\n");
}

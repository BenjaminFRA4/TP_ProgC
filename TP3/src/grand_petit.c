#include <stdio.h>
#include <stdlib.h> // Pour rand() et srand()
#include <time.h>   // Pour time()

#define TAILLE_TABLEAU 100
#define VAL_MIN 1
#define VAL_MAX 1000

int main() {
    // 1. Création du tableau d'entiers de taille 100
    int tableau[TAILLE_TABLEAU];
    int i; 
    
    // Variables pour stocker les résultats
    int plus_grand;
    int plus_petit;

    // Initialisation de la graine pour le générateur de nombres aléatoires
    srand(time(NULL)); 

    printf("--- Recherche du Plus Grand et du Plus Petit dans un Tableau ---\n");
    printf("> Taille du tableau : %d\n", TAILLE_TABLEAU);
    printf("> Plage des valeurs : [%d, %d]\n\n", VAL_MIN, VAL_MAX);

    // =================================================================
    // 2. Remplissage du tableau avec des valeurs aléatoires
    // =================================================================
    for (i = 0; i < TAILLE_TABLEAU; i++) {
        // Génère une valeur entre VAL_MIN (1) et VAL_MAX (1000)
        tableau[i] = (rand() % VAL_MAX) + VAL_MIN;
    }

    // =================================================================
    // 3. Initialisation et parcours pour la recherche
    // =================================================================
    
    // Initialisation : on prend le premier élément comme référence.
    // Cette étape est cruciale pour que la comparaison fonctionne correctement.
    plus_grand = tableau[0];
    plus_petit = tableau[0];
    
    // Boucle pour parcourir le reste du tableau (à partir de l'indice 1)
    for (i = 1; i < TAILLE_TABLEAU; i++) {
        
        // Vérification du plus grand
        if (tableau[i] > plus_grand) {
            plus_grand = tableau[i];
        }
        
        // Vérification du plus petit
        if (tableau[i] < plus_petit) {
            plus_petit = tableau[i];
        }
    }
    
    // =================================================================
    // 4. Affichage des résultats
    // =================================================================
    printf("Résultat de l'analyse :\n");
    printf("Le numéro le plus grand est : %d\n", plus_grand);
    printf("Le numéro le plus petit est : %d\n", plus_petit);
    
    printf("\n--- Recherche terminée ---\n");
    
    return 0;
}

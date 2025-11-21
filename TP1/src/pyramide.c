#include <stdio.h>
#include <stdlib.h> // Ajout pour EXIT_SUCCESS/EXIT_FAILURE et potentiel clean-up

int main() {
    int n; // Hauteur de la pyramide
    int i; 
    int j; 

    printf("--- Génération interactive d'une pyramide de nombres ---\n");
    
    // L'invite de saisie sans retour à la ligne
    printf("Veuillez saisir la hauteur de la pyramide (un nombre entier, par exemple 9) : ");
    
    // *** CORRECTION : Force l'affichage de l'invite immédiatement ***
    fflush(stdout); 

    // Lire l'entrée de l'utilisateur
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "\nErreur : Saisie invalide. Veuillez entrer un nombre entier.\n");
        return EXIT_FAILURE; 
    }

    if (n <= 0) {
        printf("\nLa hauteur doit être supérieure à zéro. La pyramide ne peut pas être générée.\n");
        return EXIT_SUCCESS;
    }
    
    printf("\n>>> Génération d'une pyramide de hauteur : %d <<<\n\n", n);

    // Boucle de génération (inchangée)
    for (i = 1; i <= n; i++) {
        
        // Espaces
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // Croissant
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // Décroissant
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        printf("\n");
    }

    printf("\n--- Génération de la pyramide terminée ---\n");

    return EXIT_SUCCESS;
}

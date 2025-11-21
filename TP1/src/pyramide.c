#include <stdio.h>

int main() {
    // Déclaration des variables
    int n; // Hauteur de la pyramide
    int i; // Compteur pour la ligne (niveau de la pyramide)
    int j; // Compteur pour les boucles internes (espaces et nombres)

    printf("--- Génération interactive d'une pyramide de nombres ---\n");
    
    // 1. Demander à l'utilisateur de saisir la hauteur (n)
    printf("Veuillez saisir la hauteur de la pyramide (un nombre entier, par exemple 9) : ");
    
    // Lire l'entrée de l'utilisateur
    if (scanf("%d", &n) != 1) {
        // Gérer le cas où l'entrée n'est pas un entier
        fprintf(stderr, "Erreur : Saisie invalide. Veuillez entrer un nombre entier.\n");
        return 1; // Quitter avec un code d'erreur
    }

    // Vérification simple de la hauteur pour une meilleure expérience
    if (n <= 0) {
        printf("La hauteur doit être supérieure à zéro. La pyramide ne peut pas être générée.\n");
        return 0;
    }
    
    printf("\n>>> Génération d'une pyramide de hauteur : %d <<<\n\n", n);

    // Boucle principale : Itère sur chaque ligne (niveau) de 1 à n
    for (i = 1; i <= n; i++) {
        
        // 1. Boucle pour afficher les ESPACES (Centrage)
        // Affiche n - i espaces.
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 2. Boucle pour afficher la partie CROISSANTE des nombres (de 1 à i)
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 3. Boucle pour afficher la partie DÉCROISSANTE des nombres (de i-1 à 1)
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Passer à la ligne suivante
        printf("\n");
    }

    // Affichage de la terminaison
    printf("\n--- Génération de la pyramide terminée ---\n");

    return 0;
}

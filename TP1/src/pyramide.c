
#include <stdio.h>

int main() {
    // Déclaration des variables
    int n; // Hauteur de la pyramide
    int i; // Compteur pour la ligne (niveau de la pyramide)
    int j; // Compteur pour les boucles internes (espaces et nombres)

    // Initialisation : n détermine la hauteur de la pyramide
    n = 5;

    printf("--- Génération d'une pyramide de nombres centrée (Hauteur : %d) ---\n\n", n);

    // Boucle principale : Ière boucle - Itère sur chaque ligne (niveau) de 1 à n
    for (i = 1; i <= n; i++) {
        
        // 1. Boucle pour afficher les ESPACES (Centrage)
        // La ligne 'i' a besoin de n - i espaces au début.
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 2. Boucle pour afficher la partie CROISSANTE des nombres (de 1 à i)
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 3. Boucle pour afficher la partie DÉCROISSANTE des nombres (de i-1 à 1)
        // Cette boucle commence à i-1 pour éviter de répéter le nombre central 'i'.
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Passer à la ligne suivante pour commencer le niveau suivant
        printf("\n");
    }

    // Affichage de la terminaison
    printf("\n--- Génération de la pyramide terminée ---\n");

    return 0;
}

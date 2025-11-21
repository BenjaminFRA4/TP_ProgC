#include <stdio.h>

void afficher_binaire(int n) {
    // Calcule le nombre de bits dans un int (normalement 32 ou 16)
    const int N_BITS = sizeof(int) * 8;
    int i;

    // Début de l'affichage
    printf("%6d en binaire est : ", n);

    // Boucle de N_BITS-1 (bit de poids fort) jusqu'à 0 (bit de poids faible)
    for (i = N_BITS - 1; i >= 0; i--) {
        // 1. Décaler n de i positions à droite (>> i). Cela amène le bit i
        //    à la position du bit 0.
        // 2. Effectuer un AND (&) avec 1 (binaire: ...0001). Cela isole le bit 0.
        int bit = (n >> i) & 1;
        
        // Afficher le bit
        printf("%d", bit);

        // Ajout d'un espace pour la lisibilité (tous les 4 bits)
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    // Les nombres à tester selon la consigne
    int tests[] = {0, 4096, 65536, 65535, 1024};
    // Calcule le nombre d'éléments dans le tableau
    int taille = sizeof(tests) / sizeof(tests[0]);
    int i;
    
    // Début du programme
    printf("--- Conversion de nombres entiers (int) en format binaire ---\n");
    printf("> Taille d'un int sur ce système: %zu octets (%zu bits)\n\n", 
           sizeof(int), sizeof(int) * 8);

    // Exécute la conversion pour chaque nombre dans le tableau
    for (i = 0; i < taille; i++) {
        afficher_binaire(tests[i]);
    }
    
    printf("------------------------------------------------------------\n");
    
    return 0;
}

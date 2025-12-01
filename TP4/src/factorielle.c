#include <stdio.h>

// Définition de la fonction factorielle récursive
long long factorielle(int num) {
    // Cas de base : 0! = 1
    if (num == 0) {
        printf("fact(0): 1\n");
        return 1;
    } 
    
    // Condition d'arrêt pour les nombres négatifs (non requis mais bonne pratique)
    if (num < 0) {
        fprintf(stderr, "La factorielle n'est pas definie pour les nombres negatifs.\n");
        return 0;
    }

    // Appel récursif : n! = n * (n-1)!
    long long valeur = num * factorielle(num - 1);
    
    // Affichage lors du retour des appels
    printf("fact(%d): %lld\n", num, valeur);
    
    return valeur;
}

int main() {
    printf("--- Exercice 4.5 : Calcul de la factorielle (recursif) ---\n");
    
    // Tests
    int test_n[] = {0, 1, 5, 10, 13}; // 13! est proche de la limite d'un 'int', 13! est la limite pour un long long sur certains systèmes
    int i;
    
    for (i = 0; i < sizeof(test_n) / sizeof(test_n[0]); i++) {
        int n = test_n[i];
        printf("\n=> Calcul de %d! :\n", n);
        long long resultat = factorielle(n);
        printf("RESULTAT FINAL pour %d! est : %lld\n", n, resultat);
    }

    return 0;
}

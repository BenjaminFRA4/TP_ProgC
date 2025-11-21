#include <stdio.h>

int main() {
    // 1. Déclaration et assignation des variables
    int a = 2; // La base
    int b = 3; // L'exposant
    
    // La variable 'resultat' doit être initialisée à 1.
    // En effet, a^0 est toujours 1, et multiplier par 1 n'affecte pas le premier cycle de la boucle.
    long long resultat = 1; 
    
    // Le type 'long long' est utilisé pour prévenir un débordement (overflow)
    // si 'a' et 'b' sont grands, car le résultat peut rapidement dépasser la capacité d'un 'int'.
    
    int i; // Compteur de la boucle

    printf("--- Calcul de la Puissance (a^b) sans utiliser pow() ---\n");
    
    // Gérer le cas spécial où l'exposant est négatif (non requis par l'énoncé mais bonne pratique)
    if (b < 0) {
        printf("Le calcul des exposants négatifs n'est pas supporté par cette implémentation.\n");
        return 1;
    }

    // Gérer le cas a^0 = 1
    if (b == 0) {
        resultat = 1;
    } else {
        // 2. Utilisation d'une boucle for pour calculer la puissance
        // Nous allons multiplier la base 'a' par elle-même 'b' fois.
        for (i = 0; i < b; i++) {
            resultat = resultat * a;
        }
    }
    
    // 3. Affichage du résultat
    printf("La base (a) : %d\n", a);
    printf("L'exposant (b) : %d\n", b);
    printf("\nLe résultat de %d à la puissance %d est : %lld\n", a, b, resultat);
    
    printf("------------------------------------------------------\n");
    
    // Testons une autre valeur (4^2 = 16)
    a = 4;
    b = 2;
    resultat = 1; // Réinitialisation du résultat
    
    for (i = 0; i < b; i++) {
        resultat = resultat * a;
    }
    printf("Test : Le résultat de %d à la puissance %d est : %lld\n", a, b, resultat);

    return 0;
}

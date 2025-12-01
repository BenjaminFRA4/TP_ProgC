#include <stdio.h>
#include <stdlib.h> // Pour EXIT_SUCCESS/FAILURE

int main() {
    // Déclaration des variables
    int n;          // Nombre de termes à générer (jusqu'à Un inclus)
    int i;          // Compteur de la boucle
    
    // Initialisation des deux premiers termes de la suite (U0 et U1)
    // Nous utilisons 'long long' pour stocker les termes, car la suite de Fibonacci croît très rapidement.
    long long u0 = 0; // Terme Un-2 (U0)
    long long u1 = 1; // Terme Un-1 (U1)
    long long un_prochain; // Terme Un

    printf("--- Génération de la Suite de Fibonacci ---\n");
    
    // Demander à l'utilisateur le nombre de termes
    printf("Veuillez saisir le rang du dernier terme à afficher (n, par exemple 7) : ");
    
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Erreur : Saisie invalide.\n");
        return EXIT_FAILURE;
    }
    
    // Gérer les cas triviaux (n < 0 ou n = 0)
    if (n < 0) {
        printf("Le rang (n) doit être un entier positif.\n");
        return EXIT_SUCCESS;
    }

    printf("\nSuite de Fibonacci jusqu'à U%d : ", n);

    // --- Génération et Affichage ---
    
    // Cas n = 0 : Afficher seulement U0
    if (n == 0) {
        printf("%lld\n", u0);
        return EXIT_SUCCESS;
    }

    // Afficher les deux premiers termes (U0 et U1)
    printf("%lld, %lld", u0, u1);

    // Boucle pour calculer les termes de U2 à Un
    // La boucle commence à i=2 car U0 et U1 sont déjà affichés.
    for (i = 2; i <= n; i++) {
        
        // Calcul du prochain terme : Un = Un-1 + Un-2
        un_prochain = u0 + u1;
        
        // Afficher le nouveau terme
        printf(", %lld", un_prochain);
        
        // Mise à jour des variables pour la prochaine itération :
        // Le terme Un-2 devient l'ancien Un-1 (stocké dans u1)
        u0 = u1;
        
        // Le terme Un-1 devient le terme que nous venons de calculer (un_prochain)
        u1 = un_prochain;
    }

    printf("\n--- Génération terminée ---\n");

    return EXIT_SUCCESS;
}

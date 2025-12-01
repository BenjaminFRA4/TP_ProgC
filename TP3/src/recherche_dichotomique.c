#include <stdio.h>
#include <stdlib.h> // Pour rand(), srand()
#include <time.h>   // Pour time()

#define TAILLE 100 // Taille du tableau

// Déclarations des fonctions
void remplir_tableau(int tab[], int taille);
void tri_a_bulles(int tab[], int taille);
void afficher_tableau(const int tab[], int taille, const char *titre);
int recherche_dichotomique(const int tab[], int taille, int cle);

int main() {
    int tableau[TAILLE];
    int entier_cherche;
    int index_trouve;

    // Initialisation du générateur aléatoire
    srand(time(NULL)); 

    printf("--- Recherche Dichotomique dans un Tableau Trié ---\n");
    
    // 1. Remplissage, Tri et Affichage
    remplir_tableau(tableau, TAILLE);
    
    printf("\nTableau initial généré (non trié) :\n");
    afficher_tableau(tableau, TAILLE, "  ");
    
    // Étape CRUCIALE pour la recherche dichotomique
    tri_a_bulles(tableau, TAILLE);
    printf("\nTableau trié par ordre croissant :\n");
    afficher_tableau(tableau, TAILLE, "  ");


    // 2. Demande de l'entier à chercher
    printf("\nEntrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &entier_cherche) != 1) {
        fprintf(stderr, "Erreur de saisie. Veuillez entrer un nombre entier.\n");
        return 1;
    }

    // 3. Recherche Dichotomique
    index_trouve = recherche_dichotomique(tableau, TAILLE, entier_cherche);

    // 4. Affichage du résultat
    printf("\nRésultat : ");
    if (index_trouve != -1) {
        printf("entier présent (à l'indice %d)\n", index_trouve);
    } else {
        printf("entier absent\n");
    }
    
    printf("\n--- Recherche terminée ---\n");

    return 0;
}

// =================================================================
// 1. Algorithme de Recherche Dichotomique
// =================================================================

/**
 * Recherche un élément dans un tableau trié en utilisant la méthode dichotomique.
 * Retourne l'indice de l'élément trouvé ou -1 s'il est absent.
 */
int recherche_dichotomique(const int tab[], int taille, int cle) {
    int debut = 0;
    int fin = taille - 1;
    int milieu;

    while (debut <= fin) {
        milieu = debut + (fin - debut) / 2; // Calcule le milieu pour éviter l'overflow
        
        if (tab[milieu] == cle) {
            return milieu; // Élément trouvé !
        }
        
        if (tab[milieu] < cle) {
            // L'élément se trouve dans la moitié supérieure
            debut = milieu + 1;
        } else {
            // L'élément se trouve dans la moitié inférieure
            fin = milieu - 1;
        }
    }
    
    return -1; // Élément absent du tableau
}

// =================================================================
// 2. Fonctions de Tri et d'Affichage (Réutilisées)
// =================================================================

/**
 * Remplit le tableau avec des entiers aléatoires entre -50 et 50.
 */
void remplir_tableau(int tab[], int taille) {
    int i;
    for (i = 0; i < taille; i++) {
        // Valeurs aléatoires entre -50 et 50
        tab[i] = (rand() % 101) - 50; 
    }
}

/**
 * Implémentation du Tri à Bulles (Bubble Sort) pour le tri croissant.
 */
void tri_a_bulles(int tab[], int taille) {
    int i, j;
    int temp; 
    for (i = 0; i < taille - 1; i++) {
        for (j = 0; j < taille - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                // Échange (Swap)
                temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}

/**
 * Affiche les premiers éléments du tableau pour la vérification.
 */
void afficher_tableau(const int tab[], int taille, const char *titre) {
    int i;
    int max_affichage = (taille > 20) ? 20 : taille; 
    
    printf("%s", titre);
    for (i = 0; i < max_affichage; i++) {
        printf("%d ", tab[i]);
    }
    if (taille > max_affichage) {
        printf("... (%d entiers au total)", taille);
    }
    printf("\n");
}

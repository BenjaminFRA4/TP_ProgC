#include <stdio.h>

int main() {

    int compteur = 5; // Tu peux changer la valeur (< 10)

    printf("=== Version avec FOR ===\n\n");

    // ------------------------------
    // VERSION 1 : Boucles FOR
    // ------------------------------
    for (int i = 1; i <= compteur; i++) {

        for (int j = 1; j <= i; j++) {

            // Lignes 1 et 2 : que des *
            if (i == 1 || i == 2) {
                printf("* ");
            }
            // Dernière ligne : que des *
            else if (i == compteur) {
                printf("* ");
            }
            // Bords : *
            else if (j == 1 || j == i) {
                printf("* ");
            }
            // Milieu : #
            else {
                printf("# ");
            }
        }
        printf("\n");
    }

    printf("\n=== Version avec WHILE ===\n\n");

    // ------------------------------
    // VERSION 2 : Boucles WHILE
    // ------------------------------
    int i = 1;

    while (i <= compteur) {

        int j = 1;

        while (j <= i) {

            if (i == 1 || i == 2) {
                printf("* ");
            }
            else if (i == compteur) {
                printf("* ");
            }
            else if (j == 1 || j == i) {
                printf("* ");
            }
            else {
                printf("# ");
            }

            j++;
        }

        printf("\n");
        i++;
    }

    return 0;
}

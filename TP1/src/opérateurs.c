#include <stdio.h>

int main() {

    int a = 16;
    int b = 3;

    // Opérateurs arithmétiques
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);   // division entière
    printf("a %% b = %d\n\n", a % b); // %% pour afficher %

    // Opérateurs de comparaison (résultat = 0 ou 1)
    printf("a == b : %d\n", a == b);
    printf("a >  b : %d\n", a > b);

    return 0;
}

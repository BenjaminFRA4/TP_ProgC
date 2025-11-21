#include <stdio.h>

int main() {

    int num1, num2;
    char op;

    printf("=== Programme de calcul interactif ===\n\n");

    // Saisie des nombres avec flush pour forcer l'affichage
    printf("Entrez num1 : ");
    fflush(stdout);
    scanf("%d", &num1);

    printf("Entrez num2 : ");
    fflush(stdout);
    scanf("%d", &num2);

    printf("Entrez un operateur (+, -, *, /, %%, &, |, ~) : ");
    fflush(stdout);
    scanf(" %c", &op);

    printf("\n--- RESULTAT ---\n");

    switch (op) {

        case '+':
            printf("%d + %d = %d\n", num1, num2, num1 + num2);
            break;

        case '-':
            printf("%d - %d = %d\n", num1, num2, num1 - num2);
            break;

        case '*':
            printf("%d * %d = %d\n", num1, num2, num1 * num2);
            break;

        case '/':
            if (num2 != 0)
                printf("%d / %d = %d\n", num1, num2, num1 / num2);
            else
                printf("Erreur : division par zero !\n");
            break;

        case '%':
            if (num2 != 0)
                printf("%d %% %d = %d\n", num1, num2, num1 % num2);
            else
                printf("Erreur : modulo par zero !\n");
            break;

        case '&':
            printf("%d & %d = %d\n", num1, num2, num1 & num2);
            break;

        case '|':
            printf("%d | %d = %d\n", num1, num2, num1 | num2);
            break;

        case '~':
            printf("~%d = %d\n", num1, ~num1);
            break;

        default:
            printf("Operateur '%c' non reconnu.\n", op);
    }

    return 0;
}

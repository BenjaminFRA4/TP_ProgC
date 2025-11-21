#include <stdio.h>

int main() {

    int num1, num2;
    char op;

    printf("=== Programme de calcul interactif ===\n\n");

    // Saisie des nombres
    printf("Entrez num1 : ");
    scanf("%d", &num1);

    printf("Entrez num2 : ");
    scanf("%d", &num2);

    // Saisie de l'opérateur
    printf("Entrez un operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op);   // Note : espace avant %c pour éviter de capter un retour à la ligne

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



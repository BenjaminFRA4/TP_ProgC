#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h" // Réutilisation des fonctions de calcul

int main(int argc, char *argv[]) {
    int num1, num2;
    char op;
    int resultat = 0;

    printf("--- Exercice 4.4 : Calculatrice en ligne de commande ---\n");

    // Vérification du nombre d'arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <operateur> <nombre1> <nombre2>\n", argv[0]);
        fprintf(stderr, "Operateurs supportes: +, -, *, /, %%, &, |, ~ (mettre '*' et '&' entre guillemets si necessaire)\n");
        return 1;
    }

    // Extraction des arguments
    op = argv[1][0]; // Le premier caractère du second argument est l'opérateur
    num1 = atoi(argv[2]); // Convertir le troisième argument en entier
    num2 = atoi(argv[3]); // Convertir le quatrième argument en entier

    printf("Operation demandee : %d %c %d\n", num1, op, num2);

    switch (op) {
        case '+': resultat = somme(num1, num2); break;
        case '-': resultat = difference(num1, num2); break;
        case '*': resultat = produit(num1, num2); break;
        case '/': 
            if (num2 != 0) {
                resultat = quotient(num1, num2);
            } else {
                fprintf(stderr, "Erreur: Division par zero.\n");
                return 1;
            }
            break;
        case '%': 
            if (num2 != 0) {
                resultat = modulo(num1, num2);
            } else {
                fprintf(stderr, "Erreur: Modulo par zero.\n");
                return 1;
            }
            break;
        case '&': resultat = op_et(num1, num2); break;
        case '|': resultat = op_ou(num1, num2); break;
        case '~': resultat = op_negation(num1, num2); break;
        default: 
            fprintf(stderr, "Erreur: Operateur non valide.\n");
            return 1;
    }

    printf("Resultat : %d\n", resultat);
    
    return 0;
}

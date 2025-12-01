#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

#define MAX_BUFFER 256

// --- Fonctions d'Entrée pour chaque Exercice ---

void exercice_4_1() {
    int num1, num2;
    char op;
    int resultat = 0;
    
    printf("\n--- Exercice 4.1 : Calcul avec operateurs ---\n");
    printf("Entrez num1 : ");
    if (scanf("%d", &num1) != 1) {
        printf("Erreur de saisie de num1.\n");
        while (getchar() != '\n');
        return;
    }
    
    printf("Entrez num2 : ");
    if (scanf("%d", &num2) != 1) {
        printf("Erreur de saisie de num2.\n");
        while (getchar() != '\n');
        return;
    }
    
    while (getchar() != '\n');
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    if (scanf("%c", &op) != 1) {
        printf("Erreur de saisie de l'operateur.\n");
        while (getchar() != '\n');
        return;
    }

    switch (op) {
        case '+': resultat = somme(num1, num2); break;
        case '-': resultat = difference(num1, num2); break;
        case '*': resultat = produit(num1, num2); break;
        case '/': 
            if (num2 != 0) {
                resultat = quotient(num1, num2);
            } else {
                printf("Erreur: Division par zero.\n");
                return;
            }
            break;
        case '%': 
            if (num2 != 0) {
                resultat = modulo(num1, num2);
            } else {
                printf("Erreur: Modulo par zero.\n");
                return;
            }
            break;
        case '&': resultat = op_et(num1, num2); break;
        case '|': resultat = op_ou(num1, num2); break;
        case '~': resultat = op_negation(num1, num2); break;
        default: printf("Operateur non valide.\n"); return;
    }

    printf("Resultat : %d\n", resultat);
}

void exercice_4_2() {
    int choix;
    char nom_de_fichier[MAX_BUFFER];
    char message[MAX_BUFFER];
    
    printf("\n--- Exercice 4.2 : Gestion de fichiers ---\n");
    printf("Que souhaitez-vous faire ?\n");
    printf("1. Lire un fichier\n");
    printf("2. Ecrire dans un fichier (Ajouter)\n");
    printf("Votre choix : ");
    
    if (scanf("%d", &choix) != 1) {
        printf("Choix invalide.\n");
        while (getchar() != '\n');
        return;
    }
    
    while (getchar() != '\n'); // Nettoyer le buffer

    printf("Entrez le nom du fichier : ");
    if (fgets(nom_de_fichier, MAX_BUFFER, stdin) == NULL) return;
    nom_de_fichier[strcspn(nom_de_fichier, "\n")] = 0; // Supprimer le \n

    if (choix == 1) {
        lire_fichier(nom_de_fichier);
    } else if (choix == 2) {
        printf("Entrez le message a ecrire : ");
        if (fgets(message, MAX_BUFFER, stdin) == NULL) return;
        message[strcspn(message, "\n")] = 0; // Supprimer le \n

        ecrire_dans_fichier(nom_de_fichier, message, "a");
    } else {
        printf("Choix non reconnu.\n");
    }
}

void exercice_4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    
    struct couleur couleurs_test[] = {
        {0xFF, 0x00, 0x00, 0xFF}, 
        {0x00, 0xFF, 0x00, 0xFF}, 
        {0x00, 0x00, 0xFF, 0xFF}, 
        {0xFF, 0xFF, 0x00, 0xFF}, 
        {0x00, 0xFF, 0xFF, 0xFF}, 
        {0xFF, 0x00, 0xFF, 0xFF}, 
        {0x80, 0x80, 0x80, 0xFF}, 
        {0xEE, 0x82, 0xEE, 0xFF}, 
        {0xFF, 0xA5, 0x00, 0xFF}, 
        {0x00, 0x00, 0x00, 0x80} 
    };
    int nb_couleurs = sizeof(couleurs_test) / sizeof(couleurs_test[0]);
    int i;
    
    printf("\n--- Exercice 4.7 : Gestion d'une liste de couleurs ---\n");
    
    for (i = 0; i < nb_couleurs; i++) {
        insertion(&couleurs_test[i], &ma_liste);
    }

    printf("Liste des couleurs (inserees par ordre inverse) :\n");
    parcours(&ma_liste);
    
    liberer_liste(&ma_liste);
}


// --- Fonction Principale (Menu) ---
int main() {
    int choix;
    
    do {
        printf("\n\n===============================================\n");
        printf("  MENU DES EXERCICES (4.1, 4.2, 4.7)\n");
        printf("===============================================\n");
        printf("1 : Exercice 4.1 (Calculatrice simple)\n");
        printf("2 : Exercice 4.2 (Gestion de fichiers Lire/Ecrire)\n");
        printf("7 : Exercice 4.7 (Liste chainee de couleurs)\n");
        printf("0 : Quitter\n");
        printf("Votre choix : ");

        if (scanf("%d", &choix) != 1) {
            printf("\nSaisie invalide. Veuillez entrer un chiffre.\n");
            while (getchar() != '\n'); 
            choix = -1;
        }
        
        switch (choix) {
            case 1:
                exercice_4_1();
                break;
            case 2:
                exercice_4_2();
                break;
            case 7:
                exercice_4_7();
                break;
            case 0:
                printf("\nProgramme termine.\n");
                break;
            default:
                printf("\nChoix non reconnu. Veuillez reessayer.\n");
                break;
        }
    } while (choix != 0);

    return 0;
}

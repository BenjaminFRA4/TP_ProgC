#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h" // Réutilisation de la structure Etudiant et ecrire_dans_fichier

#define NOM_FICHIER "etudiant.txt"

void exercice_4_3() {
    // Tableau de structures pour stocker les informations
    struct Etudiant classe[NB_ETUDIANTS_4_3];
    int i;
    
    printf("\n--- Exercice 4.3 : Gestion d'une base de donnees etudiante ---\n");

    // Écraser le fichier au début pour le nettoyer
    ecrire_dans_fichier(NOM_FICHIER, "--- DEBUT DE LA BASE DE DONNEES ETUDIANTE ---", "w"); 

    for (i = 0; i < NB_ETUDIANTS_4_3; i++) {
        printf("\nEntrez les details de l'etudiant.e %d :\n", i + 1);
        
        // Lire Nom
        printf("Nom : ");
        scanf("%49s", classe[i].nom); 
        
        // Lire Prénom
        printf("Prenom : ");
        scanf("%49s", classe[i].prenom);
        
        // Lire Adresse (utiliser fgets après scanf pour gérer les espaces)
        printf("Adresse : ");
        while(getchar() != '\n'); // Nettoyer le buffer après le dernier scanf
        fgets(classe[i].adresse, TAILLE_CHAINE, stdin);
        classe[i].adresse[strcspn(classe[i].adresse, "\n")] = 0; // Supprimer le \n
        
        // Lire Notes
        printf("Note 1 (Prog C) : ");
        scanf("%f", &classe[i].note1);
        printf("Note 2 (Syst Explo) : ");
        scanf("%f", &classe[i].note2);
        
        // Nettoyer le buffer après les notes
        while(getchar() != '\n'); 

        // Formater la ligne pour l'écriture dans le fichier
        char ligne_etudiant[MAX_BUFFER * 2];
        snprintf(ligne_etudiant, sizeof(ligne_etudiant), 
                 "%s, %s, %s, Note1: %.1f, Note2: %.1f",
                 classe[i].nom, classe[i].prenom, classe[i].adresse, 
                 classe[i].note1, classe[i].note2);

        // Appel à la fonction ecrire_dans_fichier (mode "a" pour Ajouter)
        ecrire_dans_fichier(NOM_FICHIER, ligne_etudiant, "a");
    }

    printf("\nLes details des %d etudiants ont ete enregistres dans le fichier %s.\n", NB_ETUDIANTS_4_3, NOM_FICHIER);
}

int main() {
    exercice_4_3();
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Définition de la taille de la classe
#define NB_ETUDIANTS 5
#define TAILLE_CHAINE 50 // Taille maximale pour les noms et adresses

int main() {
    // 1. Déclaration des tableaux
    
    // Tableaux pour les identités (chaînes de caractères)
    // Chaque ligne représente un étudiant. Chaque colonne stocke une chaîne.
    char noms[NB_ETUDIANTS][TAILLE_CHAINE] = {
        "Dupont", "Martin", "Petit", "Leroy", "Moreau"
    };
    char prenoms[NB_ETUDIANTS][TAILLE_CHAINE] = {
        "Alice", "Bob", "Charlie", "Diane", "Eve"
    };
    char adresses[NB_ETUDIANTS][TAILLE_CHAINE] = {
        "12 Rue de Paris",
        "34 Av. de Lyon",
        "56 Place de Marseille",
        "78 Bd. de Toulouse",
        "90 Chem. de Bordeaux"
    };

    // Tableaux pour les notes (nombres à virgule flottante)
    float notes_c[NB_ETUDIANTS] = {
        15.5, 12.0, 18.5, 9.5, 14.0
    };
    float notes_systeme[NB_ETUDIANTS] = {
        14.0, 11.5, 16.0, 10.0, 13.5
    };

    int i; // Compteur de boucle

    printf("=================================================================\n");
    printf("                  Gestion des Données Étudiantes\n");
    printf("=================================================================\n\n");

    // 2. Utilisation d'une boucle pour parcourir et afficher les détails
    for (i = 0; i < NB_ETUDIANTS; i++) {
        
        printf("--- Étudiant %d ---\n", i + 1);
        
        // Affichage des informations d'identité
        printf("  Nom & Prénom : %s %s\n", noms[i], prenoms[i]);
        printf("  Adresse      : %s\n", adresses[i]);
        
        // Affichage des notes
        printf("  Note Prog. C : %.1f/20\n", notes_c[i]);
        printf("  Note Syst. Exploitation : %.1f/20\n", notes_systeme[i]);
        
        // Affichage de la moyenne (Calcul supplémentaire pour l'intérêt)
        float moyenne = (notes_c[i] + notes_systeme[i]) / 2.0;
        printf("  Moyenne      : %.2f/20\n", moyenne);
        
        printf("\n");
    }
    
    printf("=================================================================\n");

    return EXIT_SUCCESS;
}

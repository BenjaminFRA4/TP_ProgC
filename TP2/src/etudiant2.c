#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Nécessaire pour strcpy()

// Définition de la taille de la classe et des chaînes
#define NB_ETUDIANTS 5
#define TAILLE_CHAINE 50 

// =========================================================================
// 1. Définition de la structure Etudiant
// =========================================================================
struct Etudiant {
    char nom[TAILLE_CHAINE];
    char prenom[TAILLE_CHAINE];
    char adresse[TAILLE_CHAINE];
    float note_c;              // Note du module 1 (Programmation en C)
    float note_systeme;        // Note du module 2 (Système d'exploitation)
};

int main() {
    
    // 2. Création d'un tableau de 5 éléments de cette structure
    struct Etudiant classe[NB_ETUDIANTS];
    int i; // Compteur de boucle

    printf("--- Gestion des Données Étudiantes avec Structures ---\n\n");

    // =========================================================================
    // 3. Initialisation des données des 5 étudiants
    // =========================================================================

    // Étudiant 1 : Alice Dupont
    strcpy(classe[0].nom, "Dupont");
    strcpy(classe[0].prenom, "Alice");
    strcpy(classe[0].adresse, "12 Rue de Paris");
    classe[0].note_c = 16.5;
    classe[0].note_systeme = 12.1;

    // Étudiant 2 : Bob Martin
    strcpy(classe[1].nom, "Martin");
    strcpy(classe[1].prenom, "Bob");
    strcpy(classe[1].adresse, "34 Av. de Lyon");
    classe[1].note_c = 14.0;
    classe[1].note_systeme = 14.1;

    // Étudiant 3 : Charlie Petit
    strcpy(classe[2].nom, "Petit");
    strcpy(classe[2].prenom, "Charlie");
    strcpy(classe[2].adresse, "56 Place de Marseille");
    classe[2].note_c = 18.0;
    classe[2].note_systeme = 15.5;
    
    // Étudiant 4 : Diane Leroy
    strcpy(classe[3].nom, "Leroy");
    strcpy(classe[3].prenom, "Diane");
    strcpy(classe[3].adresse, "78 Bd. de Toulouse");
    classe[3].note_c = 9.8;
    classe[3].note_systeme = 11.0;
    
    // Étudiant 5 : Eve Moreau
    strcpy(classe[4].nom, "Moreau");
    strcpy(classe[4].prenom, "Eve");
    strcpy(classe[4].adresse, "90 Chem. de Bordeaux");
    classe[4].note_c = 13.5;
    classe

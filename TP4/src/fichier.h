#ifndef FICHIER_H
#define FICHIER_H

#include <stdio.h>
#include <string.h>

// Déclarations des prototypes de fonctions de gestion de fichiers
void lire_fichier(const char *nom_de_fichier);
// Le mode peut être "w" (écraser) ou "a" (ajouter)
void ecrire_dans_fichier(const char *nom_de_fichier, const char *message, const char *mode);

// Définition de la structure Étudiant pour l'Exercice 4.3
#define TAILLE_CHAINE 50 
#define NB_ETUDIANTS_4_3 5

struct Etudiant {
    char nom[TAILLE_CHAINE];
    char prenom[TAILLE_CHAINE];
    char adresse[TAILLE_CHAINE];
    float note1; // Programmation C
    float note2; // Système d'exploitation
};

#endif // FICHIER_H

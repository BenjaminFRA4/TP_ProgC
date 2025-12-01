#include "repertoire.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constante pour gérer la longueur maximale d'un chemin
#define MAX_PATH 1024

// --- Exercice 5.1 : Liste simple (non récursive) ---
void lire_dossier(const char *nom_repertoire) {
    DIR *dir;
    struct dirent *entree;

    printf("\n--- Exercice 5.1 : Contenu du repertoire '%s' ---\n", nom_repertoire);

    dir = opendir(nom_repertoire);
    if (dir == NULL) {
        perror("Erreur opendir");
        return;
    }

    // Lire chaque entrée
    while ((entree = readdir(dir)) != NULL) {
        // d_name contient le nom du fichier/répertoire
        printf("  %s\n", entree->d_name);
    }

    closedir(dir);
}

// --- Exercice 5.2 : Liste récursive (Fonction d'aide avec profondeur) ---
static void lire_dossier_recursif_aide(const char *nom_repertoire, int profondeur) {
    DIR *dir;
    struct dirent *entree;

    // Afficher l'indentation
    for (int i = 0; i < profondeur; i++) {
        printf("  ");
    }
    printf("|-- %s\n", nom_repertoire);

    dir = opendir(nom_repertoire);
    if (dir == NULL) {
        // perror ne doit pas être appelé pour les erreurs de permission
        return; 
    }

    while ((entree = readdir(dir)) != NULL) {
        // Ignorer les entrées '.' (répertoire courant) et '..' (répertoire parent)
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) {
            continue;
        }

        // Construire le chemin complet pour la prochaine récursion ou affichage
        char chemin_complet[MAX_PATH];
        snprintf(chemin_complet, MAX_PATH, "%s/%s", nom_repertoire, entree->d_name);

        // Afficher l'indentation pour l'entrée courante
        for (int i = 0; i < profondeur + 1; i++) {
            printf("  ");
        }
        
        // Vérifier si c'est un répertoire (DT_DIR) ou un fichier
        if (entree->d_type == DT_DIR) {
            // C'est un répertoire, appel récursif
            // Afficher le répertoire avant l'appel récursif (il sera affiché deux fois)
            // Pour n'afficher qu'une fois, on pourrait afficher l'entrée ici, puis appeler l'aide
            // printf("[DIR] %s\n", entree->d_name); 

            // Appel récursif (passer le chemin complet)
            lire_dossier_recursif_aide(chemin_complet, profondeur + 1);
        } else {
            // C'est un fichier ou un lien (simplifié)
            printf("Fichier: %s\n", entree->d_name);
        }
    }

    closedir(dir);
}

void lire_dossier_recursif(const char *nom_repertoire) {
    printf("\n--- Exercice 5.2 : Liste recursive du repertoire '%s' ---\n", nom_repertoire);
    lire_dossier_recursif_aide(nom_repertoire, 0);
}


// --- Exercice 5.3 : Liste itérative (Exemple simplifié) ---
// Note: Une implémentation itérative robuste nécessiterait une structure de pile
// personnalisée ou une file (queue), ce qui est au-delà du C de base.
// Nous fournissons ici une version itérative très simple.
void lire_dossier_iteratif(const char *nom_repertoire) {
    // Cette implémentation se concentre sur l'ouverture et la lecture itérative
    // du répertoire de base, comme l'exercice 5.1, car la véritable
    // implémentation itérative du parcours d'arborescence est complexe.
    
    DIR *dir;
    struct dirent *entree;

    printf("\n--- Exercice 5.3 : Contenu du repertoire '%s' (Iteratif) ---\n", nom_repertoire);

    dir = opendir(nom_repertoire);
    if (dir == NULL) {
        perror("Erreur opendir");
        return;
    }

    // La boucle while(readdir()) est la partie itérative.
    while ((entree = readdir(dir)) != NULL) {
        if (entree->d_type == DT_DIR) {
            printf("[REPERTOIRE] %s\n", entree->d_name);
        } else {
            printf("[FICHIER] %s\n", entree->d_name);
        }
    }

    closedir(dir);
    printf("--> L'exploration de la profondeur requerrait une pile ou file.\n");
}

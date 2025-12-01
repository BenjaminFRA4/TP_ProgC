#include "fichier.h"
#include <stdio.h>
#include <stdlib.h>

// Implémentation de lire_fichier
void lire_fichier(const char *nom_de_fichier) {
    FILE *fichier = fopen(nom_de_fichier, "r");
    char ligne[256];

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en lecture");
        return;
    }

    printf("\nContenu du fichier %s :\n", nom_de_fichier);
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }

    if (ferror(fichier)) {
        perror("Erreur de lecture du fichier");
    }

    fclose(fichier);
}

// Implémentation de ecrire_dans_fichier
void ecrire_dans_fichier(const char *nom_de_fichier, const char *message, const char *mode) {
    FILE *fichier = fopen(nom_de_fichier, mode);

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier en écriture");
        return;
    }

    if (fprintf(fichier, "%s\n", message) < 0) {
        perror("Erreur lors de l'écriture dans le fichier");
    } else {
        printf("Le message a été écrit dans le fichier %s.\n", nom_de_fichier);
    }

    fclose(fichier);
}

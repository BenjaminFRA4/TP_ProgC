#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIGNE 512
#define MAX_PHRASE 100

// Déclaration de la fonction de recherche de sous-chaîne sans strstr (custom)
// Retourne le nombre d'occurrences
int compter_occurrences(const char *ligne, const char *phrase);

int main() {
    char nom_fichier[MAX_PHRASE];
    char phrase_recherchee[MAX_PHRASE];
    char ligne[MAX_LIGNE];
    int num_ligne = 0;
    int total_occurrences = 0;
    FILE *fichier;

    printf("--- Exercice 4.6 : Recherche de phrases dans un fichier ---\n");
    
    printf("Entrez le nom du fichier : ");
    if (scanf("%99s", nom_fichier) != 1) return 1;
    
    printf("Entrez la phrase que vous souhaitez rechercher : ");
    // Nettoyer le buffer après le scanf du nom de fichier
    while (getchar() != '\n');
    if (fgets(phrase_recherchee, MAX_PHRASE, stdin) == NULL) return 1;
    phrase_recherchee[strcspn(phrase_recherchee, "\n")] = 0; // Supprimer le \n

    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur: Impossible d'ouvrir le fichier");
        return 1;
    }

    printf("\nResultats de la recherche :\n");

    // Parcourir chaque ligne du fichier
    while (fgets(ligne, MAX_LIGNE, fichier) != NULL) {
        num_ligne++;
        int occurrences = compter_occurrences(ligne, phrase_recherchee);
        
        if (occurrences > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, occurrences);
            total_occurrences += occurrences;
        }
    }

    fclose(fichier);

    if (total_occurrences == 0) {
        printf("La phrase \"%s\" n'a ete trouvee dans aucune ligne.\n", phrase_recherchee);
    }
    
    return 0;
}

// Implémentation de la recherche de sous-chaîne sans strstr
int compter_occurrences(const char *ligne, const char *phrase) {
    int compteur = 0;
    int i = 0; // Pointeur dans la ligne
    int j = 0; // Pointeur dans la phrase
    
    int len_ligne = 0;
    while(ligne[len_ligne] != '\0') len_ligne++;
    
    int len_phrase = 0;
    while(phrase[len_phrase] != '\0') len_phrase++;

    if (len_phrase == 0) return 0;

    // Boucle principale sur la ligne (s'arrête quand il n'y a plus assez de caractères pour la phrase)
    while (i <= len_ligne - len_phrase) {
        
        // Vérification de la première lettre
        if (ligne[i] == phrase[0]) {
            // Tentative de correspondance complète
            for (j = 1; j < len_phrase; j++) {
                if (ligne[i + j] != phrase[j]) {
                    break; // La correspondance a échoué
                }
            }
            
            // Si la boucle interne s'est terminée car j a atteint la longueur de la phrase,
            // alors c'est une correspondance complète.
            if (j == len_phrase) {
                compteur++;
                // Avancer le pointeur de recherche dans la ligne au-delà de la phrase trouvée
                i += len_phrase; 
            } else {
                i++; // Avancer d'un seul caractère
            }
        } else {
            i++; // Avancer d'un seul caractère
        }
    }

    return compteur;
}

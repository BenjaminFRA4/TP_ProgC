#include <stdio.h>
#include <stdbool.h> // Pour utiliser le type bool

#define NB_PHRASES 10
#define TAILLE_MAX_PHRASE 100 // Taille maximale pour la phrase à chercher

// Déclaration de la fonction de comparaison sans bibliothèque standard
bool comparer_chaines_custom(const char *chaine1, const char *chaine2);

int main() {
    // 1. Création d'un tableau de 10 phrases
    // (Tableau de chaînes de caractères / Tableau de tableaux de caractères)
    const char phrases[NB_PHRASES][TAILLE_MAX_PHRASE] = {
        "Bonjour, comment ca va ?",
        "Le temps est magnifique aujourd'hui.",
        "C'est une belle journee.",
        "La programmation en C est amusante.",
        "Les tableaux en C sont puissants.",
        "Les pointeurs en C peuvent etre deroutants.",
        "Il fait beau dehors.",
        "La recherche dans un tableau est interessante.",
        "Les structures de donnees sont importantes.",
        "Programmer en C, c'est genial."
    };
    
    // Phrase à rechercher (nous utilisons un tableau pour la saisie utilisateur)
    char phrase_a_chercher[TAILLE_MAX_PHRASE];
    bool phrase_trouvee = false;
    int i;

    printf("--- Recherche d'une Phrase dans un Tableau (Sans strcmp) ---\n\n");
    
    // Affichage des phrases disponibles (pour référence)
    printf("Phrases disponibles :\n");
    for (i = 0; i < NB_PHRASES; i++) {
        printf("  %d. %s\n", i + 1, phrases[i]);
    }

    // Demander à l'utilisateur d'entrer la phrase à chercher
    printf("\nEntrez la phrase exacte a chercher (max %d caracteres) :\n> ", TAILLE_MAX_PHRASE - 1);
    
    // Utiliser fgets pour lire la ligne, y compris les espaces
    // Le '\n' lu par fgets doit être retiré pour la comparaison
    if (fgets(phrase_a_chercher, TAILLE_MAX_PHRASE, stdin) != NULL) {
        // Retirer le caractère de nouvelle ligne ('\n') ajouté par fgets
        size_t longueur = 0;
        while (phrase_a_chercher[longueur] != '\0') {
            if (phrase_a_chercher[longueur] == '\n') {
                phrase_a_chercher[longueur] = '\0'; // Remplacer '\n' par le caractère nul de fin
                break;
            }
            longueur++;
        }
    } else {
        return 1; // Erreur de lecture
    }

    // =================================================================
    // Logique de Recherche Linéaire (utilisant la fonction custom)
    // =================================================================
    
    for (i = 0; i < NB_PHRASES; i++) {
        // Appeler la fonction de comparaison personnalisée
        if (comparer_chaines_custom(phrase_a_chercher, phrases[i])) {
            phrase_trouvee = true;
            break; // Sortir dès que la correspondance est trouvée
        }
    }

    // Affichage du résultat final
    printf("\nRecherche pour \"%s\" :\n", phrase_a_chercher);
    if (phrase_trouvee) {
        printf("Resultat : Phrase trouvee\n");
    } else {
        printf("Resultat : Phrase non trouvee\n");
    }

    printf("\n--- Fin de la recherche ---\n");
    
    return 0;
}

// =================================================================
// Fonction de Comparaison Caractère par Caractère (sans bibliothèque)
// =================================================================

/**
 * Compare deux chaînes de caractères, caractère par caractère.
 * Retourne true si les chaînes sont identiques (incluant la fin '\0'), false sinon.
 * @param chaine1 La première chaîne (celle cherchée).
 * @param chaine2 La seconde chaîne (celle du tableau).
 */
bool comparer_chaines_custom(const char *chaine1, const char *chaine2) {
    int i = 0;

    // Boucle tant que nous ne sommes pas à la fin des deux chaînes
    while (chaine1[i] != '\0' || chaine2[i] != '\0') {
        
        // 1. Comparer les caractères actuels
        if (chaine1[i] != chaine2[i]) {
            return false; // Caractère différent trouvé, les chaînes ne sont pas identiques
        }
        
        i++;
    }

    // 2. Vérification finale : Si les chaînes sont de longueurs différentes
    //    (par exemple, si l'une se termine et l'autre non, la boucle est finie
    //    mais les '\0' ne sont pas au même endroit).
    //    Si la boucle while est sortie, cela signifie que le '\0' a été atteint
    //    simultanément dans les deux chaînes.

    // Si nous arrivons ici, les chaînes sont identiques, y compris le caractère nul final.
    return true; 
}

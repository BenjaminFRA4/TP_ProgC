#include <stdio.h> // Seul include nécessaire pour printf
#include <stdlib.h> // Pour EXIT_SUCCESS

// Définition de la taille maximale des chaînes pour éviter les dépassements de mémoire (buffer overflow)
#define TAILLE_MAX 100

// --- 1. Calculer la Longueur (my_strlen) ---
/**
 * Calcule la longueur d'une chaîne de caractères (sans le '\0').
 */
int my_strlen(const char chaine[]) {
    int longueur = 0;
    
    // Parcourir la chaîne tant que le caractère n'est pas le caractère nul ('\0')
    while (chaine[longueur] != '\0') {
        longueur++;
    }
    
    return longueur;
}

// --- 2. Copier une Chaîne (my_strcpy) ---
/**
 * Copie la chaîne source dans la chaîne de destination.
 */
void my_strcpy(char destination[], const char source[]) {
    int i = 0;
    
    // Parcourir la chaîne source caractère par caractère
    while (source[i] != '\0') {
        destination[i] = source[i]; // Copier le caractère
        i++;
    }
    
    // AJOUT ESSENTIEL : Terminer la chaîne de destination par le caractère nul
    destination[i] = '\0';
}

// --- 3. Concaténer deux Chaînes (my_strcat) ---
/**
 * Ajoute la chaîne source à la fin de la chaîne de destination.
 */
void my_strcat(char destination[], const char source[]) {
    int i = 0;
    int j = 0;
    
    // A. Trouver la fin de la chaîne de destination
    // Utiliser i pour trouver le '\0' de la destination
    while (destination[i] != '\0') {
        i++;
    }
    
    // Maintenant, i pointe vers la position du '\0' dans destination
    
    // B. Ajouter les caractères de la source à partir de cette position
    while (source[j] != '\0') {
        destination[i + j] = source[j]; // Copier le caractère source[j] à destination[i+j]
        j++;
    }
    
    // AJOUT ESSENTIEL : Terminer la nouvelle chaîne par le caractère nul
    destination[i + j] = '\0';
}


// --- Fonction Principale (main) ---
int main() {
    // Déclaration et initialisation des chaînes de caractères
    char chaine1[] = "Hello";
    char chaine2[] = " World!";
    
    // Chaîne de destination pour la copie (doit être assez grande)
    char copie[TAILLE_MAX];
    
    // Chaîne pour la concaténation (doit être assez grande et contenir la première chaîne)
    // Nous copions chaine1 dans concat pour pouvoir y ajouter chaine2
    char concat[TAILLE_MAX];
    
    int longueur;

    printf("--- Manipulation de Chaînes de Caractères sans bibliothèques standard ---\n\n");

    // =========================================================================
    // 1. Calcul de la Longueur
    // =========================================================================
    longueur = my_strlen(chaine1);
    printf("1. Longueur de \"%s\" est : %d\n", chaine1, longueur);
    
    longueur = my_strlen(chaine2);
    printf("   Longueur de \"%s\" est : %d\n", chaine2, longueur);

    printf("----------------------------------------------------------------------\n");

    // =========================================================================
    // 2. Copie de Chaîne
    // =========================================================================
    my_strcpy(copie, chaine1);
    printf("2. Chaîne source : \"%s\"\n", chaine1);
    printf("   Chaîne copiée : \"%s\"\n", copie);

    printf("----------------------------------------------------------------------\n");

    // =========================================================================
    // 3. Concaténation de Chaînes
    // =========================================================================
    // Préparer la chaîne de destination en copiant la première chaîne
    my_strcpy(concat, chaine1); 
    
    // Concaténer la deuxième chaîne
    my_strcat(concat, chaine2);
    
    printf("3. Chaîne 1 (Base) : \"%s\"\n", chaine1);
    printf("   Chaîne 2 (Ajout) : \"%s\"\n", chaine2);
    printf("   Chaîne concaténée : \"%s\"\n", concat);
    
    printf("----------------------------------------------------------------------\n");

    return EXIT_SUCCESS;
}

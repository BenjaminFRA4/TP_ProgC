#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Nécessaire pour memcpy pour les types flottants

// Définition du caractère (type char)
void afficher_et_manipuler_char(char v_char);
// Définition de l'entier court (type short)
void afficher_et_manipuler_short(short v_short);
// Définition de l'entier standard (type int)
void afficher_et_manipuler_int(int v_int);
// Définition de l'entier long (type long int)
void afficher_et_manipuler_long(long v_long);
// Définition de l'entier très long (type long long int)
void afficher_et_manipuler_long_long(long long v_long_long);
// Définition du flottant standard (type float)
void afficher_et_manipuler_float(float v_float);
// Définition du flottant double précision (type double)
void afficher_et_manipuler_double(double v_double);
// Définition du flottant longue double précision (type long double)
void afficher_et_manipuler_long_double(long double v_long_double);


// Fonction utilitaire pour afficher la valeur en hexadécimal
// C'est nécessaire car printf n'a pas de spécificateur simple pour afficher
// la représentation binaire (donc hexadécimale) des types float/double.
void afficher_valeur_hexa(const void *ptr, size_t size) {
    const unsigned char *p = (const unsigned char *)ptr;
    int i;
    
    // Affichage de la valeur en ordre décroissant (big-endian) ou croissant (little-endian)
    // dépend du système. L'important est de voir les octets bruts.
    for (i = size - 1; i >= 0; i--) {
        printf("%02X", p[i]);
    }
}


int main() {
    printf("=================================================================================\n");
    printf("  Manipulation des Variables de Types de Base avec Pointeur (Adresses et Valeurs Hexa)\n");
    printf("=================================================================================\n\n");
    
    // Initialisation des variables de base (réutilisation de variables.c)
    char v_char = 'A';
    short v_short = -32768; // Min value for a 16-bit short
    int v_int = 0xAA55AA55; // Un motif Hexa
    long v_long = 1234567890L;
    long long v_long_long = 9876543210LL;
    float v_float = 2.0f; // Représentation en IEEE 754: 4000 0000 (si 32-bit float)
    double v_double = 3.1415926535;
    long double v_long_double = 4.2L;

    // Appel des fonctions de manipulation pour chaque type
    afficher_et_manipuler_char(v_char);
    afficher_et_manipuler_short(v_short);
    afficher_et_manipuler_int(v_int);
    afficher_et_manipuler_long(v_long);
    afficher_et_manipuler_long_long(v_long_long);
    afficher_et_manipuler_float(v_float);
    afficher_et_manipuler_double(v_double);
    afficher_et_manipuler_long_double(v_long_double);
    
    printf("\n=================================================================================\n");

    return 0;
}

// --- Fonctions de Manipulation et d'Affichage ---

void afficher_et_manipuler_char(char v_char) {
    char *ptr = &v_char;
    
    printf("--- Type: char (1 octet) ---\n");
    printf("  Avant manipulation:\n");
    printf("  Adresse de char : %p, Valeur de char : ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(char));
    printf("\n");
    
    // Manipulation par pointeur
    *ptr = 'B';
    
    printf("  Après manipulation:\n");
    printf("  Adresse de char : %p, Valeur de char : ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(char));
    printf(" (Nouvelle valeur: '%c')\n\n", *ptr);
}

void afficher_et_manipuler_short(short v_short) {
    short *ptr = &v_short;
    
    printf("--- Type: short (2 octets) ---\n");
    printf("  Avant manipulation:\n");
    printf("  Adresse de short: %p, Valeur de short: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(short));
    printf("\n");
    
    // Manipulation par pointeur
    *ptr = 1000;
    
    printf("  Après manipulation:\n");
    printf("  Adresse de short: %p, Valeur de short: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(short));
    printf(" (Nouvelle valeur: %hd)\n\n", *ptr);
}

void afficher_et_manipuler_int(int v_int) {
    int *ptr = &v_int;
    
    printf("--- Type: int (4 octets) ---\n");
    printf("  Avant manipulation:\n");
    printf("  Adresse de int  : %p, Valeur de int  : ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(int));
    printf("\n");
    
    // Manipulation par pointeur
    *ptr = 0xDEADBEEF;
    
    printf("  Après manipulation:\n");
    printf("  Adresse de int  : %p, Valeur de int  : ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(int));
    printf(" (Nouvelle valeur: %d)\n\n", *ptr);
}

void afficher_et_manipuler_long(long v_long) {
    long *ptr = &v_long;
    
    printf("--- Type: long int (%zu octets) ---\n", sizeof(long));
    printf("  Avant manipulation:\n");
    printf("  Adresse de long : %p, Valeur de long : ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(long));
    printf("\n");
    
    // Manipulation par pointeur
    *ptr = -5000000L;
    
    printf("  Après manipulation:\n");
    printf("  Adresse de long : %p, Valeur de long : ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(long));
    printf(" (Nouvelle valeur: %ld)\n\n", *ptr);
}

void afficher_et_manipuler_long_long(long long v_long_long) {
    long long *ptr = &v_long_long;
    
    printf("--- Type: long long int (8 octets) ---\n");
    printf("  Avant manipulation:\n");
    printf("  Adresse de llong: %p, Valeur de llong: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(long long));
    printf("\n");
    
    // Manipulation par pointeur
    *ptr = 1000000000000LL;
    
    printf("  Après manipulation:\n");
    printf("  Adresse de llong: %p, Valeur de llong: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(long long));
    printf(" (Nouvelle valeur: %lld)\n\n", *ptr);
}

void afficher_et_manipuler_float(float v_float) {
    float *ptr = &v_float;
    
    printf("--- Type: float (4 octets) ---\n");
    printf("  Avant manipulation:\n");
    printf("  Adresse de float: %p, Valeur de float: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(float));
    printf("\n");
    
    // Manipulation par pointeur (changement à 1.0f -> 3F800000 en hex)
    *ptr = 1.0f; 
    
    printf("  Après manipulation:\n");
    printf("  Adresse de float: %p, Valeur de float: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(float));
    printf(" (Nouvelle valeur: %.1f)\n\n", *ptr);
}

void afficher_et_manipuler_double(double v_double) {
    double *ptr = &v_double;
    
    printf("--- Type: double (8 octets) ---\n");
    printf("  Avant manipulation:\n");
    printf("  Adresse de double: %p, Valeur de double: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(double));
    printf("\n");
    
    // Manipulation par pointeur
    *ptr = 100.0; 
    
    printf("  Après manipulation:\n");
    printf("  Adresse de double: %p, Valeur de double: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(double));
    printf(" (Nouvelle valeur: %.1f)\n\n", *ptr);
}

void afficher_et_manipuler_long_double(long double v_long_double) {
    long double *ptr = &v_long_double;
    
    printf("--- Type: long double (%zu octets) ---\n", sizeof(long double));
    printf("  Avant manipulation:\n");
    printf("  Adresse de ldouble: %p, Valeur de ldouble: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(long double));
    printf("\n");
    
    // Manipulation par pointeur
    *ptr = 5.5L; 
    
    printf("  Après manipulation:\n");
    printf("  Adresse de ldouble: %p, Valeur de ldouble: ", (void*)ptr);
    afficher_valeur_hexa(ptr, sizeof(long double));
    printf(" (Nouvelle valeur: %.1Lf)\n\n", *ptr);
}

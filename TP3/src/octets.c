#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // Pour size_t

// Déclaration de la fonction utilitaire
void afficher_octets(const void *ptr_variable, size_t taille, const char *nom_type);

int main() {
    // Initialisation des variables avec des valeurs faciles à visualiser en hexadécimal
    // (Les valeurs flottantes sont choisies pour avoir une représentation hexadécimale connue)
    
    short v_short = 0x0302;         // Attendu: 02 03 (Little-Endian) ou 03 02 (Big-Endian)
    int v_int = 0x04030201;         // Attendu: 01 02 03 04 (Little-Endian)
    long v_long = 0x0807060504030201L; // 8 octets si long est 64-bit
    float v_float = 1.0f;           // Attendu: 00 00 80 3F (Little-Endian) pour 1.0f (IEEE 754)
    double v_double = 2.0;          // Attendu: 00 00 00 00 00 00 00 40 (Little-Endian) pour 2.0 (IEEE 754)
    long double v_long_double = 3.0L;

    printf("--- Affichage des Octets Individuels des Types de Données ---\n");
    printf("> L'ordre ci-dessous indique l'Endianness de votre machine.\n\n");

    // Affichage des octets pour chaque type
    afficher_octets(&v_short, sizeof(v_short), "short");
    printf("\n");
    
    afficher_octets(&v_int, sizeof(v_int), "int");
    printf("\n");
    
    afficher_octets(&v_long, sizeof(v_long), "long int");
    printf("\n");
    
    afficher_octets(&v_float, sizeof(v_float), "float");
    printf("\n");
    
    afficher_octets(&v_double, sizeof(v_double), "double");
    printf("\n");
    
    afficher_octets(&v_long_double, sizeof(v_long_double), "long double");
    printf("\n");

    printf("--------------------------------------------------------------\n");

    return 0;
}

// =================================================================
// FONCTION UTILITAIRE : Affichage des Octets
// =================================================================

/**
 * Affiche la représentation mémoire (octets) d'une variable donnée.
 * * @param ptr_variable : Pointeur générique vers la variable (son adresse).
 * @param taille : Taille en octets de la variable.
 * @param nom_type : Nom du type de la variable.
 */
void afficher_octets(const void *ptr_variable, size_t taille, const char *nom_type) {
    // 1. Caster le pointeur générique (void*) en pointeur sur octet (unsigned char*)
    // Un unsigned char est garanti d'être de la taille d'un octet (1 byte) et non signé,
    // ce qui est idéal pour manipuler les données brutes de la mémoire.
    const unsigned char *ptr_octet = (const unsigned char *)ptr_variable;
    size_t i;

    printf("Octets de %s (%zu octets) :\n ", nom_type, taille);
    
    // 2. Parcourir les octets
    // L'arithmétique des pointeurs est utilisée : (ptr_octet + i) pour obtenir
    // l'adresse du i-ème octet, et * pour déréférencer et obtenir sa valeur.
    for (i = 0; i < taille; i++) {
        // Afficher la valeur de l'octet courant en hexadécimal sur deux chiffres (%02X)
        printf("%02X ", *(ptr_octet + i));
    }
    printf("\n");
}

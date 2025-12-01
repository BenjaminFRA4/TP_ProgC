#include <stdio.h>
#include <stddef.h> // Pour size_t et NULL

int main() {
    // Déclaration de variables pour les types de base
    char c = 'a';
    short s = 0;
    int i = 0;
    long l = 0;
    long long ll = 0;
    float f = 0.0f;
    double d = 0.0;
    long double ld = 0.0L;

    // Déclaration de pointeurs
    char *ptr_c = &c;
    int *ptr_i = &i;
    float *ptr_f = &f;
    
    // Déclaration de pointeurs de pointeurs
    int **ptr_i_i = &ptr_i;
    char ***ptr_c_c_c = NULL; // Initialisation à NULL pour l'exemple

    printf("--- Comprendre la Taille des Types de Données (sizeof.c) ---\n");
    printf("> Architecture 64 bits (les pointeurs sont normalement sur 8 octets)\n\n");
    
    printf("=================================================================\n");
    printf("  Types de Base\n");
    printf("=================================================================\n");
    printf("La taille de char (octet) est       : %zu octets\n", sizeof(char));
    printf("La taille de short est              : %zu octets\n", sizeof(short));
    printf("La taille de int est                : %zu octets\n", sizeof(int));
    printf("La taille de long int est           : %zu octets\n", sizeof(long int));
    printf("La taille de long long int est      : %zu octets\n", sizeof(long long int));
    printf("La taille de float est              : %zu octets\n", sizeof(float));
    printf("La taille de double est             : %zu octets\n", sizeof(double));
    printf("La taille de long double est        : %zu octets\n", sizeof(long double));
    
    printf("=================================================================\n");
    printf("  Types Pointeur (Adresses)\n");
    printf("=================================================================\n");
    // L'opérateur sizeof retourne la taille du POINTEUR lui-même, qui stocke une adresse mémoire.
    
    printf("La taille de char* (pointeur sur char) est : %zu octets\n", sizeof(char*));
    printf("La taille de int* (pointeur sur int) est   : %zu octets\n", sizeof(int*));
    printf("La taille de float* (pointeur sur float) est : %zu octets\n", sizeof(float*));
    
    printf("-----------------------------------------------------------------\n");
    
    // Test des pointeurs de pointeurs
    printf("La taille de int** est             : %zu octets\n", sizeof(int**));
    printf("La taille de char** est            : %zu octets\n", sizeof(char**));
    printf("La taille de char*** est           : %zu octets\n", sizeof(char***));
    printf("La taille de float** est           : %zu octets\n", sizeof(float**));
    printf("La taille de float*** est          : %zu octets\n", sizeof(float***));

    printf("=================================================================\n");
    
    return 0;
}

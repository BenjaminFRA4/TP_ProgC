#include <stdio.h>
#include <stdlib.h>

// Définition du nombre de couleurs
#define NB_COULEURS 10

// =========================================================================
// 1. Définition de la structure CouleurRGBA
// =========================================================================
struct CouleurRGBA {
    unsigned char R; // Rouge (Red)
    unsigned char G; // Vert (Green)
    unsigned char B; // Bleu (Blue)
    unsigned char A; // Alpha (Transparence)
};

int main() {
    
    // 2. Création d'un tableau de 10 structures
    struct CouleurRGBA palette[NB_COULEURS];
    int i; 

    printf("--- Gestion des Couleurs au Format RGBA avec Structures ---\n\n");

    // =========================================================================
    // 3. Initialisation des 10 couleurs en notation hexadécimale
    // =========================================================================
    
    // Assurez-vous que chaque ligne se termine par un point-virgule ';' !
    palette[0] = (struct CouleurRGBA){ .R = 0xEF, .G = 0x78, .B = 0x12, .A = 0xFF }; 
    palette[1] = (struct CouleurRGBA){ .R = 0x2C, .G = 0xC8, .B = 0x64, .A = 0xFF }; 
    palette[2] = (struct CouleurRGBA){ .R = 0xFF, .G = 0x00, .B = 0x00, .A = 0xFF }; 
    palette[3] = (struct CouleurRGBA){ .R = 0x00, .G = 0x00, .B = 0xFF, .A = 0xFF }; 
    palette[4] = (struct CouleurRGBA){ .R = 0x00, .G = 0xFF, .B = 0x00, .A = 0xFF }; 
    palette[5] = (struct CouleurRGBA){ .R = 0x80, .G = 0x80, .B = 0x80, .A = 0xFF }; 
    palette[6] = (struct CouleurRGBA){ .R = 0x00, .G = 0x00, .B = 0x00, .A = 0x80 }; 
    
    // Ligne 41 du précédent code (palette[8]) - doit être palette[7] ou [8] selon votre numérotation.
    // Je mets palette[7] ici pour continuer la séquence :
    palette[7] = (struct CouleurRGBA){ .R = 0xFF, .G = 0xFF, .B = 0xFF, .A = 0xFF }; 
    
    palette[8] = (struct CouleurRGBA){ .R = 0xC0, .G = 0xC0, .B = 0xC0, .A = 0xFF }; // C'est l'indice [8] dans le tableau (9ème couleur)
    palette[9] = (struct CouleurRGBA){ .R = 0xDA, .G = 0xA5, .B = 0x20, .A = 0xFF }; // C'est l'indice [9] dans le tableau (10ème couleur)

    // =========================================================================
    // 4. Affichage des 10 couleurs
    // =========================================================================
    printf("========================================================\n");
    printf("  Index | Rouge (R) | Vert (G) | Bleu (B) | Alpha (A) \n");
    printf("========================================================\n");

    for (i = 0; i < NB_COULEURS; i++) {
        // Le format %u affiche l'unsigned char comme un entier non-signé (0-255)
        printf("Couleur %2d :", i + 1);
        // Affichage Décimal (u) et Hexadécimal (X)
        printf("  %5u (0x%02X)", palette[i].R, palette[i].R);
        printf("  %5u (0x%02X)", palette[i].G, palette[i].G);
        printf("  %5u (0x%02X)", palette[i].B, palette[i].B);
        printf("  %5u (0x%02X)\n", palette[i].A, palette[i].A);
    }
    
    printf("========================================================\n");

    return EXIT_SUCCESS; // FIN de la fonction main()
} // FIN du fichier

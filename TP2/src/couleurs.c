#include <stdio.h>
#include <stdlib.h>

// Définition du nombre de couleurs
#define NB_COULEURS 10

// =========================================================================
// 1. Définition de la structure CouleurRGBA
// Chaque composant est un octet (unsigned char) pour contenir 0 à 255.
// =========================================================================
struct CouleurRGBA {
    unsigned char R; // Rouge (Red)
    unsigned char G; // Vert (Green)
    unsigned char B; // Bleu (Blue)
    unsigned char A; // Alpha (Transparence)
};

int main() {
    
    // 2. Création d'un tableau de 10 éléments de cette structure
    struct CouleurRGBA palette[NB_COULEURS];
    int i; 

    printf("--- Gestion des Couleurs au Format RGBA avec Structures ---\n\n");

    // =========================================================================
    // 3. Initialisation des 10 couleurs en notation hexadécimale (0xNN)
    // =========================================================================
    
    // Les valeurs sont données en Hexadécimal (0x00 à 0xFF)
    // Exemple : 0xef = 239, 0x78 = 120, 0x12 = 18, 0xff = 255

    palette[0] = (struct CouleurRGBA){ .R = 0xEF, .G = 0x78, .B = 0x12, .A = 0xFF }; // Couleur demandée dans l'exemple
    palette[1] = (struct CouleurRGBA){ .R = 0x2C, .G = 0xC8, .B = 0x64, .A = 0xFF }; // Vert clair (Exemple 2)
    palette[2] = (struct CouleurRGBA){ .R = 0xFF, .G = 0x00, .B = 0x00, .A = 0xFF }; // Rouge pur
    palette[3] = (struct CouleurRGBA){ .R = 0x00, .G = 0x00, .B = 0xFF, .A = 0xFF }; // Bleu pur
    palette[4] = (struct CouleurRGBA){ .R = 0x00, .G = 0xFF, .B = 0x00, .A = 0xFF }; // Vert pur
    palette[5] = (struct CouleurRGBA){ .R = 0x80, .G = 0x80, .B = 0x80, .A = 0xFF }; // Gris moyen
    palette[6] = (struct CouleurRGBA){ .R = 0x00, .G = 0x00, .B = 0x00, .A = 0x80 }; // Noir (Semi-transparent)
    palette[7] = (struct CouleurRGBA){ .R = 0xFF, .G = 0xFF, .B = 0xFF, .A = 0xFF }; // Blanc
    palette[8] = (struct CouleurRGBA){ .R = 0xC0, .G = 0xC0, .B

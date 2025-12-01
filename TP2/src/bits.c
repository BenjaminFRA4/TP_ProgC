#include <stdio.h>

int main() {
    // 1. Déclaration et initialisation de la variable
    // Nous allons tester avec un nombre où ces deux bits sont mis à 1.
    // Position du 4ème bit de gauche : 32 - 4 = 28
    // Position du 20ème bit de gauche : 32 - 20 = 12
    
    // Le nombre est (1 << 28) + (1 << 12) = 268435456 + 4096 = 268439552
    int d = 268439552;
    // Représentation binaire de d (32 bits) : 
    // 1000 0000 0000 0100 0000 0000 0000 0000
    
    // Vérification de la taille (pour la portabilité, bien que le code utilise 32 par défaut)
    const int N_BITS = sizeof(int) * 8; 
    
    // Calcul des positions à partir de la droite (base 0)
    const int POS_4_GAUCHE = N_BITS - 4;   // 32 - 4 = 28
    const int POS_20_GAUCHE = N_BITS - 20; // 32 - 20 = 12
    
    int bit_4;
    int bit_20;
    
    // Affichage des informations
    printf("--- Vérification des bits (sur %d bits) ---\n", N_BITS);
    printf("Valeur d (Décimal) : %d\n", d);
    printf("Positions des bits vérifiés : 4ème et 20ème de GAUCHE (Positions %d et %d de DROITE)\n", POS_4_GAUCHE, POS_20_GAUCHE);
    
    // 2. Opérations de manipulation de bits
    
    // Extraction du 4ème bit de gauche (bit à la position 28)
    // 1. Décaler le bit 28 à la position 0.
    // 2. Effectuer un AND avec 1 pour isoler ce bit.
    bit_4 = (d >> POS_4_GAUCHE) & 1;
    
    // Extraction du 20ème bit de gauche (bit à la position 12)
    bit_20 = (d >> POS_20_GAUCHE) & 1;
    
    printf("\n> 4ème bit de gauche (Pos %d) est : %d\n", POS_4_GAUCHE, bit_4);
    printf("> 20ème bit de gauche (Pos %d) est : %d\n", POS_20_GAUCHE, bit_20);
    
    // 3. Vérification des deux bits
    // Les deux doivent être 1.
    if (bit_4 == 1 && bit_20 == 1) {
        printf("\nRésultat final : %d (Les deux bits sont à 1)\n", 1);
    } else {
        printf("\nRésultat final : %d (Au moins un des bits n'est pas à 1)\n", 0);
    }
    
    printf("--------------------------------------------\n");
    
    return 0;
}

#ifndef REPERTOIRE_H
#define REPERTOIRE_H

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>

// Exercice 5.1 : Liste simple (non récursive)
void lire_dossier(const char *nom_repertoire);

// Exercice 5.2 : Liste récursive
void lire_dossier_recursif(const char *nom_repertoire);

// Exercice 5.3 : Liste itérative (version simplifiée, car l'implémentation complète
// iterative est beaucoup plus complexe et nécessite une pile ou une file personnalisée)
void lire_dossier_iteratif(const char *nom_repertoire); 

#endif // REPERTOIRE_H

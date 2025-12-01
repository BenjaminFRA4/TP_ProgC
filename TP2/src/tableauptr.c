Manipulation de Tableaux avec des Pointeurs

Dans cet exercice, l'objectif est de créer un programme en C nommé tableauptr.c pour gérer deux tableaux différents : un tableau d'entiers (int) et un tableau de nombres à virgule flottante (float). Le programme doit remplir ces tableaux avec des valeurs aléatoires. Ensuite, pour les deux tableaux, il doit multiplier par 3 la valeur à chaque position dont l'indice est divisible par 2. La particularité de cet exercice est que vous ne devez pas utiliser la notation indicielle (par exemple, i[3], i[5], etc.) pour parcourir les tableaux, mais plutôt utiliser des pointeurs.

Instructions :

Déclarez deux tableaux, l'un d'entiers (int) et l'autre de nombres à virgule flottante (float).
Utilisez une boucle pour remplir les tableaux avec des valeurs aléatoires. Vous pouvez utiliser la fonction rand() pour générer des valeurs aléatoires. Assurez-vous d'utiliser la fonction srand(time(NULL)) pour initialiser la graine du générateur de nombres aléatoires.
Utilisez des pointeurs pour parcourir les tableaux et effectuer la multiplication par 3 sur les valeurs dont l'indice est divisible par 2.
Assurez-vous que le programme affiche les tableaux avant et après la multiplication par 3.
Exemple :

Un exemple d'utilisation de ce programme pourrait être :

Le programme génère des tableaux aléatoires, par exemple :

Tableau d'entiers (avant la multiplication par 3) :

11, 12, 34, 56, 78, 90, 123, 45, 67, 89, 100
Tableau de nombres à virgule flottante (avant la multiplication par 3) :

2.9, 1.23, 4.56, 7.89, 0.12, 3.45, 6.78, 9.01, 2.34, 5.67, 8.90
Le programme effectue la multiplication par 3 sur les valeurs dont l'indice est divisible par 2 :

Tableau d'entiers (après la multiplication par 3) :

11, 12, 34, 168, 78, 270, 123, 135, 67, 267, 100
Tableau de nombres à virgule flottante (après la multiplication par 3) :

2.9, 1.23, 4.56, 23.67, 0.12, 10.35, 6.78, 27.03, 2.34, 17.01, 8.90
Assurez-vous que le programme fonctionne correctement en utilisant des pointeurs pour parcourir les tableaux et effectuer la multiplication par 3 sur les valeurs appropriées.

Astuce
Pour l'exercice 2.5, pensez à utiliser *(s+i) etc (e.g, si s est un pointeur de type int *).

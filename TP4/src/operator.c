#include "operator.h"

int somme(int num1, int num2) { return num1 + num2; }
int difference(int num1, int num2) { return num1 - num2; }
int produit(int num1, int num2) { return num1 * num2; }
int quotient(int num1, int num2) { return num1 / num2; }
int modulo(int num1, int num2) { return num1 % num2; }
int op_et(int num1, int num2) { return num1 & num2; }
int op_ou(int num1, int num2) { return num1 | num2; }
int op_negation(int num1, int num2) { return ~num1; }

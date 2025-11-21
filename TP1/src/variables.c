#include <stdio.h>

int main() {

    // char
    signed char c1 = -10;
    unsigned char c2 = 250;

    // short
    signed short s1 = -32000;
    unsigned short s2 = 65000;

    // int
    signed int i1 = -2000000000;
    unsigned int i2 = 4000000000U;

    // long int
    signed long int l1 = -500000L;
    unsigned long int l2 = 500000UL;

    // long long int
    signed long long int ll1 = -9000000000000000000LL;
    unsigned long long int ll2 = 18000000000000000000ULL;

    // float
    float f = 3.14f;

    // double
    double d = 2.718281828;

    // long double
    long double ld = 1.234567890123456789L;

    // Affichage
    printf("signed char            : %d\n", c1);
    printf("unsigned char          : %u\n\n", c2);

    printf("signed short           : %d\n", s1);
    printf("unsigned short         : %u\n\n", s2);

    printf("signed int             : %d\n", i1);
    printf("unsigned int           : %u\n\n", i2);

    printf("signed long int        : %ld\n", l1);
    printf("unsigned long int      : %lu\n\n", l2);

    printf("signed long long int   : %lld\n", ll1);
    printf("unsigned long long int : %llu\n\n", ll2);

    printf("float                  : %f\n", f);
    printf("double                 : %f\n", d);
    printf("long double            : %Lf\n", ld);

    return 0;
}

#include <stdio.h>

int somme (int a, int b) {
    int résultat = a + b;
    return résultat;
}

int main () {
    int c = somme (7,18);
    printf("%d\n", c);
    return 0;
}
#include <stdio.h>

int main () {

int tab[4] = {2, 2, 2, 1};
int somme;



    for(int i = 0; i < 4; i++) {
        somme = tab[i] + somme;
        printf("%d           %d\n", tab[i], somme);
    }

    return 0;
}
#include <stdio.h>

int main () {

    int valeur[6] = {7, 3, 4, 5, 2, 103};
    int compteur = 0;
    int  pair;

    for (int i = 0; i < 6; i++) {
        printf("%d\n", valeur[i]);
    }

    for (int i = 0; i < 6; i++) {

        if (valeur[i] % 2 == 0) {
            compteur ++;
            pair = valeur[i];
        }

        if (compteur >= 2) {
            break;
        }

    }
        
    printf("le deuxième chiffre pair est %d\n", pair);
        
    return 0;
}
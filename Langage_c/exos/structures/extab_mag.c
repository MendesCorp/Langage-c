#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct produit {
    char * nom;
    float prix;
    int stock;
} t_produit;

int main () {

    t_produit truc[4] = {
        {"ordinateur", 799.99, 10},
        {"souris", 19.99, 50},
        {"clavier", 49.99, 30},
        {"écran", 149.99, 15}
    };

    for (int i = 0; i < 4; i++) {

        if (truc[i].prix < 60.0) {
            printf ("%s : %f€   x%d\n", truc[i].nom, truc[i].prix, truc[i].stock);
        }

    }
    
    return 0;
}

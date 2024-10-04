#include <stdio.h>

int main () {

    int notes[5]= {10, 12, 15, 9, 11};
    int coefs[5]= {1, 2, 1, 3, 8};
    int notes_coefs[5];
    int produit = 0;
   

    for(int i = 0 ; i < 5; i++) {
         notes_coefs[i] = notes[i] * coefs[i];
        printf("%d\n", notes_coefs[i]);
    }

    return 0;
    
}


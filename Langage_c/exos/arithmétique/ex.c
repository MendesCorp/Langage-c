#include <stdio.h>

int main () {

int notes[5]= {10, 20, 15, 12, 3} ;
int notedix[1];
int notessup[3];
int noteinf[1];
int compteur1 = 0;
int compteur2 = 0;
int compteur3 = 0;

    for(int i = 0; i < 5; i++) {
        notedix[i] = notes[i];
        notessup[i] = notes[i];
        noteinf[i] = notes[i];
        compteur1 ++;
        compteur2 ++;
        compteur3 ++;

        
        if(notes[i] == 10) {
            printf("Il y a %d note égale à 10\n", compteur1);
        }
        
        notessup[i] == 3;
        
        if(compteur2 > 3) {
            break;    
        }
        printf("Il y a %d notes supérieures à 10\n", compteur2);

        noteinf[i] == 1;

        if(compteur3 > 1) {
            break;
        }
        printf("Il y a %d note inférieure à 10\n", compteur3);


    }

    return 0;
}

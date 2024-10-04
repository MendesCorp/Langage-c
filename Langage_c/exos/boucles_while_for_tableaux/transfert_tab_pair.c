#include <stdio.h>

int main () {

   int tab[4] = {4, 5, 112, 21};
   int tabli[4];
   int i = 0; 

        while(i < 4) {

            if(tab[i] % 2 == 0) {
                tabli[i] = tab[i];
            }

            i++;
        }

        for(int y = 0; y < 4; y++) {
            printf("%d\n", tabli[y]);
        }

        for(int y = 0; y < 4; y++) {
            printf("%d\n", tab[y]);
        }
        
    return 0;
}
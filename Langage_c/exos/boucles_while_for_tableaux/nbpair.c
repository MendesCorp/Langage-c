#include <stdio.h>

int main() {

int tab[4] = {4, 5, 112, 21};
int i =0;

    for(int i = 0; i < 4; i++) {
        printf("%d [%d]\n", i, tab[i]);
    
    if(i % 2 == 0) {
        printf("%d est un nombre pair\n", tab[i]);
    }

    }

    return 0;
}
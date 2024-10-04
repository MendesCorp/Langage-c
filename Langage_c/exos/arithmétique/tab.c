#include <stdio.h>

int main () {

int tab[10]= {11,45,68,128,77777,69,55,287,3333,10};

int i = 0;

int produit = 1;

while(i < 10) {
    produit =  produit * tab[i];
    i++;

if(produit % 2 == 0) {

   printf("%d est un nb pair\n", produit);
    
} else { 
    printf("%d est un nb impair\n", produit);
}

}

return 0;

}


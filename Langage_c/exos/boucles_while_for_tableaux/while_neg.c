#include <stdio.h>

int main () {

    int i = -10; 
    int quotient = 0;
    
    while(i < 50) {
        i++;
        quotient = quotient + i;
        printf("%d\n", quotient);
    }

    return 0;
}
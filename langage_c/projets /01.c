#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    while(1){
        float r = (float)rand()/RAND_MAX * 2 + 1 ;
        printf("%f\n",r);
    }
    return 0;
}
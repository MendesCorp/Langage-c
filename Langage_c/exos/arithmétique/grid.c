#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {


    int tab[3][5] = {{0, 0, 0, 0, 0}, {1, 1, 1, 1, 1}, {0, 1, 0, 1, 0}};
    int i, y;
    printf("    01234\n    #####\n");
    srand(time(NULL));

    for (y = 0; y < 3; y++) {
        printf("%d # ", y);

        for (i = 0; i < 5; i++) {

            tab[y][i] = rand() %2 + 7;
            printf("%d",tab[y][i]);
    }

        printf("\n");
    }

    return 0;
}
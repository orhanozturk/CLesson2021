#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

//mulakat sorusu

int main()
{
    int a[10][5] = {
        [4] = {1, 2, 3, 4, 5},
        [7] = {2, 2, 1, 2, 3},
        [9] = {5, 5, 5, 5, 5},
    };

    for (int i = 0; i < 10; ++i) {
        for (int k = 0; k < 5; ++k) {
            printf("%d ", a[i][k]);
        }
        printf("\n");
    }
}


/****************************************************/
/****************************************************/









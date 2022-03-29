#include <stdio.h>
#include "utility.h"
#include <math.h>

#define     SIZE        10

int main()
{
    int a[SIZE];

    randomize();
    for(int i = 0; i < SIZE; ++i){
        a[i] = rand() % 20 + 1;
    }

    print_array(a, SIZE);

    for (int i = 0; i < SIZE; ++i) {
        for (int k = 0; k < a[i] ; ++k) {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}


/****************************************************/
/****************************************************/






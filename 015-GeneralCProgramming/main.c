#include <stdio.h>
#include "utility.h"
#include <ctype.h>

#define     SIZE        20

int is_than(int x)
{
    return x < 500;
}

int main()
{
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int i;

    for (i = 0; i < SIZE && is_than(a[i]); ++i)
        ;

    int k;

    if(i == SIZE){
        printf("butun ogeler kosulu salıyor\n");
    }
    else{
        for (k = i+1; k < SIZE; ++k) {
            if (is_than(a[k])) {
                int temp = a[i];
                a[i] = a[k];
                a[k] = temp;
                ++i;
            }
        }
    }

    printf("partisyon noktasi indxsi = %d\n", i);
    print_array(a, SIZE);

    return 0;
}


/****************************************************/
/****************************************************/






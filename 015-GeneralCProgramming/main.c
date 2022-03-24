#include <stdio.h>
#include "utility.h"

#define     SIZE        100

int main()
{
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);


    return 0;
}


/****************************************************/
/****************************************************/






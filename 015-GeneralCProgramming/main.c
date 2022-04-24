#include <stdio.h>
#include "utility.h"

#define     SIZE        20

int main()
{
    int a[SIZE];

    set_array_random(a, SIZE);
    print_array(a, SIZE);
    print_array(a, 5); //ilk 5 elemanı
    print_array(a + 5, 3); //5 index dahil ile 8 index arasını yazdıracam
    print_array(&a[5], 3); //5 index dahil  ile 8 index arasını yazdıracam
    print_array(a + SIZE -4, 4); //son 4 elemanı yazdıracam
    print_array(&a[SIZE -4], 4); //son 4 elemanı yazdıracam

}


/****************************************************/
/****************************************************/






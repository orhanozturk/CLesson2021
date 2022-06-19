#include <stdio.h>
#include "utility.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


#define     SIZE        100

int cmpfunc(const void *vpx, const void *vpy)
{
    if(*(const int *)vpx > *(const int *)vpy)
        return 1;

    if(*(const int *)vpx < *(const int *)vpy)
        return -1;

    return 0;
}

void gbsort(void *vpa, size_t size, size_t sz, int (*fcmp)(const void *, const void *))
{
    char *p = vpa;

    for (size_t i = 0; i < size -1; ++i) {
        for (size_t k = 0; k < size -1 -i; ++k) {
            if(fcmp(p+k*sz, p+(k+1)*sz) > 0)
                gswap(p+k*sz, p+(k+1)*sz, sz);
        }
    }

}

int main()
{
    int a[SIZE];
    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    gbsort(a, SIZE, sizeof (int), &cmpfunc);

    print_array(a, SIZE);
}


/****************************************************/
/****************************************************/









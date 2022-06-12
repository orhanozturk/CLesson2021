#include <stdio.h>
#include "utility.h"
#include <string.h>

#define     SIZE        10


int main()
{
    int x = 10;
    int y = 20;

    void *vp= &x;

    void **vptr = &vp;
    *vptr = &y; //vp = &y


    printf("val = %d\n", *(int *)vp);

}


/****************************************************/
/****************************************************/









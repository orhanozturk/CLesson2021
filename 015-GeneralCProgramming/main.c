#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <string.h>

#define SIZE    100

int icmp(const void *vp1, const void *vp2)
{
    return *(const int *)vp1 - *(const int *)vp2;
}

int get_median(const int *p, size_t size)
{
    int *pd = malloc(size * sizeof (int));

    if(!pd){
        printf("bellek yetrsiz\n");
        exit(EXIT_FAILURE);
    }

    memcpy(pd, p, size * sizeof (int));
    qsort(pd, size, sizeof (*pd), &icmp);

    //bunu sakın sakına ypamayın bellek sızıntısı olur
    return pd[size / 2];

    //alınan bloklar eri verilmeli

    //yapmamız geren işlem bu
    /*
    int result = pd[size / 2];

    free(pd);

    return result;
    */
}

int main()
{
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int median = get_median(a, SIZE);
    printf("median = %d\n", median);

}


/****************************************************/
/****************************************************/









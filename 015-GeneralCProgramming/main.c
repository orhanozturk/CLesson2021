#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <string.h>

#define SIZE    100


int *create_random_array(size_t n, int low, int high)
{
    int *pd = (int *)malloc(n * sizeof (int));

    if(pd == NULL){
        printf("bellek yetersiz\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n; ++i) {
        pd[i] = rand() % (high - low + 1);
    }

    return pd;
}


int main()
{
    size_t n;
    int low, high;

    printf("kac elemanli dizi : ");
    scanf("%zu", &n);
    printf("aralik degerleri : ");
    scanf("%d%d", &low, &high);

    int *pd = create_random_array(n, low, high);
    print_array(pd, n);
    sort_array(pd, n);
    dashline();
    print_array(pd, n);
    free(pd);

}


/****************************************************/
/****************************************************/









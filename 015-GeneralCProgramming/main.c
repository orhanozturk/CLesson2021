#include <stdio.h>
#include "utility.h"

#define     SIZE        10

//bir dizinin en buyuk elemanını adresinin döndüren
//array_max isimli bir donksiyon tanımlayın

int *array_max(const int *pa, size_t size)
{
    //const T * --- T*
    int *pmax = (int *)pa;

    for (size_t i = 1; i < size; ++i) {
        if(pa[i] > *pmax)
            pmax = (int *)(pa + i);
    }

    return pmax;
}

int *array_min(const int *pa, size_t size)
{
    //const T * --- T*
    int *pmin = (int *)pa;

    for (size_t i = 1; i < size; ++i) {
        if(pa[i] < *pmin)
            pmin = (int *)(pa + i);
    }

    return pmin;
}

int main()
{
    int a[SIZE];

    randomize();
    set_array_random(a, SIZE);
    print_array(a, SIZE);

    int *pmax = array_max(a, SIZE);
    int *pmin = array_min(a, SIZE);

    //tek bir deyim ile dizinini en buyk ve en kucuk degerlerini degistirelim

    swap(pmax, pmin);

    print_array(a, SIZE);

}


/****************************************************/
/****************************************************/







#include <stdio.h>
#include "utility.h"
#include "date.h"
#include <stdlib.h>
#include <time.h>

//n degeri buyuk bir sayi olmak üzere standart inputtan alınacak
//n elemanlı dinamik bir date dizisi olsuturulacak
//dizinin elemanari rastgele degerlerle set edilecek
//dizi standart qsort işleviyle kucukten buyuge sıralanacak
//sırlanmıs dizi standart outputa yazdıralacak
//sıralmaa kac sanıye sürecek hesaplanıp ekrana yazdıralacak

int dcmp(const void *vp1, const void *vp2)
{
    return cmp_date((const Date *)vp1, (const Date *)vp2);
}

void set_date_array_random(Date *pa, size_t size)
{
    while (size--) {
        set_date_random(pa++);
    }
}

void print_date_array(const Date *pa, size_t size)
{
    while (size--) {
        print_date(pa++);
    }
}

int main()
{
    int n;

    printf("kac tarih :");
    scanf("%d", &n);

    Date *p = (Date*)malloc(n * sizeof (Date*));

    if(!p){
        printf("bellek yetersiz\n");
        return 1;
    }

    set_date_array_random(p, n);
    printf("siralama basladi\n");
    clock_t start = clock();
    qsort(p, n, sizeof (*p), &dcmp);
    clock_t end = clock();
    printf("siralama bitti %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
    clear_input_buffer();
    printf("bir tusa basin\n");
    getchar();
    print_date_array(p, n);


    free(p);

}

/****************************************************/
/****************************************************/








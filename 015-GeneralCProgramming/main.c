#include <stdio.h>
#include "person.h"
#include <stdlib.h>
#include "utility.h"
#include <time.h>

void set_person_array(Person *p, size_t size)
{
    while (size--) {
        set_person_random(p++);
    }
}

void print_person_array(const Person *p, size_t size)
{
    while (size--) {
        print_person(p++);
    }
}

int pcmp(const void *p1, const void *p2)
{
    return cmp_person((const Person *)p1, (const Person *)p2);
}

int main()
{
    int n;
    printf("kac kisi : ");
    scanf("%d", &n);

    Person *pd = (Person *)malloc(n * sizeof (Person));

    if(!pd){
        fprintf(stderr, "bellek yetersiz\n");
        return 1;
    }

    set_person_array(pd, n);

    printf("siralama basladi\n");
    clock_t start = clock();
    qsort(pd, n, sizeof (*pd), &pcmp);
    clock_t end = clock();
    printf("siralama bitti %f saniye\n", (double)(end-start) / CLOCKS_PER_SEC);
    clear_input_buffer();
    (void)getchar();
    print_person_array(pd, n);

    return 0;
}


/****************************************************/
/****************************************************/








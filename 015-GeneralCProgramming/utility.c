#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef  __linux__
#include <unistd.h>
#elif _WIN32
#include <Windows.h>
#endif


const int primes[] = {
    2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
    31, 37, 41, 47, 53, 59, 61, 67, 71,
    73, 79, 83, 89, 97, 101, 103, 107,
    109, 113, 127, 131, 137, 139, 149, 151,
};

int isprime(int val)
{
    if(val == 0 || val == 1)
        return 0;

    if(val % 2 == 0)
        return val == 2;

    if(val % 3 == 0)
        return val == 3;

    if(val % 5 == 0)
        return val == 5;

    for(int k = 7; k * k <= val; k += 2)
        if(val % k == 0)
            return 0;

    return 1;
}

int ndigit(int val)
{
    if(val == 0)
        return 1;

    int digit_count = 0;

    while (val) {
        ++digit_count;
        val /= 10;
    }

    return digit_count;
}

void dashline()
{
    printf("\n-------------------------------------------------------------------------------\n");
}

void xSleep(double sec)
{
#ifdef __linux__
    sleep((double)sec * 1000);
#elif _WIN32
    Sleep((double)sec * 1000);
#endif
}

void randomize()
{
    srand((unsigned)time(NULL));
}


void set_array_random(int *p, size_t size)
{
    while (size--){
        *p++ = rand() % 1000;
    }
}


void print_array(const int *p, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        if(i && i % 20 == 0)
            printf("\n");
        printf("%3d ", p[i]);
    }

   // dashline();
    printf("\n");
}


void sgets(char *p)
{
    int c;

    while ((c = getchar()) != '\n') {
        *p++ = (char )c;
    }

    *p = '\0';
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_str(const char *p)
{
    //ikiside aynı ifade
    //while(*p != '\0') {
    while(*p) {
        printf("%c ", *p++);
    }
    putchar('\n');
}

void gswap(void *vp1, void *vp2, size_t n)
{
    char *p1 = (char *)vp1;
    char *p2 = (char *)vp2;

    while (n--) {
        char temp = *p1;
        *p1++ = *p2;
        *p2++ = temp;
    }
}

//internal linkage
static int icmp(const void *vp1, const void *vp2)
{
    if(*(const int *)vp1 > *(const int *)vp2)
        return 1;

    if(*(const int *)vp1 < *(const int *)vp2)
        return -1;

    return 0;
}

void sort_array(int *p, size_t size)
{
    qsort(p, size, sizeof (*p), &icmp);
}


void clear_input_buffer(void)
{
    int c;

    while((c = getchar()) != '\n' && c != EOF)
        ;
}

void sleep(int millisecond)
{
    clock_t start = clock();

    while (1) {
        clock_t newclock = clock();
        if((double)(newclock - start) / CLOCKS_PER_SEC * 1000 > millisecond)
            return;
    }
}



#ifndef UTILITY_H
#define UTILITY_H

#include <stddef.h>

#define     isleap(y)       ((y) % 4 == 0 && ((y) % 100 || (y) % 400 == 0))
#define     asize(x)        (sizeof(x) / sizeof(x[0]))

int isprime(int);
int ndigit(int);
void dashline(void);
void xSleep(double sec);
void randomize();
void set_array_random(int *p, size_t size);
void print_array(const int *p, size_t size);
void sgets(char *p);
void swap(int *a, int *b);


#endif // UTILITY_H

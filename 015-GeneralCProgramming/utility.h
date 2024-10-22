#ifndef UTILITY_H
#define UTILITY_H

#include <stddef.h>

//#define     isleap(y)       ((y) % 4 == 0 && ((y) % 100 || (y) % 400 == 0))
#define     asize(x)        (sizeof(x) / sizeof(x[0]))
#define     relem(a)        a[rand() % asize(a)]

#define     SETBITCOUNT(x)  (sbc_[(x) & 255] + sbc_[(x) >> 8 & 255] + sbc_[(x) >> 16 & 255] + sbc_[(x) >> 24 & 255])

extern const int primes[];
extern const int sbc_[];

int isprime(int);
int ndigit(int);
void dashline(void);
void xSleep(double sec);
void randomize();
void set_array_random(int *p, size_t size);
void print_array(const int *p, size_t size);
void sgets(char *p);
void swap(int *a, int *b);
void print_str(const char *);
void gswap(void *vp1, void *vp2, size_t n);
int icmp(const void *vp1, const void *vp2);
void sort_array(int *p, size_t size);
void clear_input_buffer(void);
void sleep(int millisecond);
void bprint(int x);

const char * random_name(void);
const char * random_surname(void);
const char * random_town(void);


#endif // UTILITY_H

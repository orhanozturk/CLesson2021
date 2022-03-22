#ifndef UTILITY_H
#define UTILITY_H

#define     isleap(y)       ((y) % 4 == 0 && ((y) % 100 || (y) % 400 == 0))

int isprime(int);
int ndigit(int);
void dashline(void);
void xSleep(double sec);
void randomize();


#endif // UTILITY_H

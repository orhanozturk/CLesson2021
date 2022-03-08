#include "utility.h"
#include <stdio.h>
#include <Windows.h>

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
    printf("\n----------------------------------------------------------------------\n");
}

void sleep(double sec)
{
    Sleep((double)sec * 1000);
}

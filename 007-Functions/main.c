#include <stdio.h>


int func(int x)
{
    if(x < 0)
        return 0;

    if(x > 10 && x < 20)
        return x;

}

int main()
{
    int y = func(26); // çöp deger

    return 0;
}


/****************************************************/
/****************************************************/

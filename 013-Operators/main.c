#include <stdio.h>
#include <math.h>


int main()
{
    int x;

    printf("4 basamakli bir sayi giriniz : ");
    scanf("%d", &x);

    printf("%d sayisinin tersi %d\n", x, x / 1000 + x / 100 % 10 * 10 + x % 100 / 10 * 100 + x % 10 * 1000);

    return 0;
}

/*************************************************/
/*************************************************/

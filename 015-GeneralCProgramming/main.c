#include <stdio.h>
#include <time.h>
#include <locale.h>
#include "utility.h"

#define   SIZE   200000


int main()
{
    //su andan 50 gun 15 saat 30 sanyie onceki olan timepoint'i hesaplayalım

    time_t t;
    time(&t);
    struct tm x = *localtime(&t);

    x.tm_mday -= 50;
    x.tm_hour -= 15;
    x.tm_sec  -= 30;

    time_t result = mktime(&x);

    if(result == -1)
        printf("donuturme islmei yapilamadi\n");
    else
        printf("%s", asctime(&x));

}


/****************************************************/
/****************************************************/








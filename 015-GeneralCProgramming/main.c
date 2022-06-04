#include <stdio.h>
#include "utility.h"
#include <string.h>

#define     SIZE        10



int main()
{

    char source[100] = "okanersoy";
    char dest[100] = "tarkanyesil";


    if(!strncmp(source +1, dest + 3, 3))
        printf("yazilar esit\n");
    else
       printf("yazilar esit degil\n");

}


/****************************************************/
/****************************************************/









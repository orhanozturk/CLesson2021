#include <stdio.h>
#include "utility.h"
#include <string.h>

#define     SIZE        100


int main()
{
   char str[SIZE];

   printf("bir isim girin : ");
   sgets(str);

   memmove(str +5, str, strlen(str) + 1);

   printf("%s\n", str);

}


/****************************************************/
/****************************************************/









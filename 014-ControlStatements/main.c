#include <stdio.h>
#include <ctype.h>

//yazıdaki rakam karaterlerinin sayısını sayan program


int main()
{
   printf("bir yazın girin : ");
   int ch;
   int count = 0;

   while ((ch = getchar()) != '\n') {
       if(isdigit(ch))
           ++count;
   }


    printf("%d  tane \n", count);

    return 0;
}

/*****************************************/
/*****************************************/











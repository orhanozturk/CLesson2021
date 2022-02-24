#include <stdio.h>
#include <ctype.h>

//fonksiyonel macrolar

#define     ISLEAP(x)       ( (x) % 4 == 0 && ( (x) % 100 || (x) % 400 == 0 ) )

int main()
{
    int y;
    printf("yil giriniz : ");
    scanf("%d", &y);

    if(ISLEAP(y)){
        printf("artik yil\n");
    }
    else {
        printf("artik yil deildir\n");
    }



}



/*****************************************/
/*****************************************/











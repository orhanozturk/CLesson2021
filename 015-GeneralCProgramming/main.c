#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include <string.h>
#include <stdbool.h>

#define  URAND_MAX      100

//unique random number generator
//0 dahil 100 haric bu aralıkta arstgele uretecek
//fonksiyon uretecek sayı kalmadıgında -1 hatası dondurecek

int urand(void)
{
    static int a[URAND_MAX] = {0};
    static int count = 0;

    if(count == URAND_MAX){
        return -1;
    }

    int val;
    while(a[val = rand() % URAND_MAX])
        ;

    a[val] = 1;
    ++count;
    return val;
}

int main()
{
    randomize();
    for (int i = 0; i < URAND_MAX; ++i) {
        printf("%d ", urand());
    }

    printf("\n");
    printf("%d ", urand()); //-1

}


/****************************************************/
/****************************************************/








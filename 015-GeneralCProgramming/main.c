#include <stdio.h>
#include "utility.h"
#include <string.h>
#include <ctype.h>

#define     SIZE        100

//stricmp
//kendimiz yazalım

int mystricmp(const char *p1, const char *p2)
{
    while (toupper(*p1) == toupper(*p2)) {
        if(*p1 == '\0')
            return 0;
        ++p1;
        ++p2;
    }


    return toupper(*p1) - toupper(*p2);
}


int main()
{
    char s1[SIZE];
    char s2[SIZE];

    printf("birinci yaziyi girin : ");
    sgets(s1);

    printf("ikinci yaziyi girin : ");
    sgets(s2);

    if(!mystricmp(s1, s2))
        printf("evet \n");
    else
        printf("hayir\n");


}


/****************************************************/
/****************************************************/






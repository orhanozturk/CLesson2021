#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utility.h"
#include <string.h>
#include <time.h>


int main(int argc, char **argv)
{
    FILE *f = fopen("person.txt", "r");

    if(!f){
        printf("dosya acilamadi\n");
        return 1;
    }


    char buffer[1000];


    while (fgets(buffer, 1000, f)) {
        //_strrev(buffer);
        printf("%s", buffer);
        _getch();
    }

    fclose(f);
}


/****************************************************/
/****************************************************/








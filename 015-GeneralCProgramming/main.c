#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "utility.h"
#include <string.h>
#include <time.h>
#include "person.h"


#define         BUFFER_SIZE 100

int main(int argc, char **argv)
{
    FILE *fs = fopen("person.dat", "rb");

    if(!fs){
        fprintf(stderr, "dosya acilamadi\n");
        return 1;
    }

    fseek(fs, 0L, SEEK_END);

    printf("the value of the file is %ld\n", ftell(fs));

    fclose(fs);
}


/****************************************************/
/****************************************************/








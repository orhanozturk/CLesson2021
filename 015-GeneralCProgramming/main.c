#include <stdio.h>
#include <conio.h>

//karaterSay.exe orhan.txt  k

int main(int argc, char **argv)
{
    if(argc != 3){
        fprintf(stderr, "kullanim : <karaterSay.exe> <orhan.txt> <karakter>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");

    if(!f){
        fprintf(stderr, "%s dosyasi acilamadi\n", argv[1]);
        return 2;
    }

    int ch;
    int count = 0;
    int total_chars = 0;

    while ((ch = fgetc(f)) != EOF) {
        if(ch == *argv[2])
            ++count;
        ++total_chars;
    }

    fclose(f);

    printf("%d / (%d)\n", count , total_chars);
}


/****************************************************/
/****************************************************/








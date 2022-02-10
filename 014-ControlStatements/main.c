#include <stdio.h>
#include <conio.h>

int main()
{
    int c;

    printf("evet mi (e) hayir mi (h) : ");


    while((c = _getch()) != 'e' && c != 'h')
        ;// null statment

    putchar(c);
    putchar('\n');


    return 0;
}

/*****************************************/
/*****************************************/











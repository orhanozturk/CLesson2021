#include <stdio.h>


#pragma pack(1)


enum Color{White, Gray, Yellow, Green, Red, Brown, Black};

const char *const pcolor[] = {"White", "Gray", "Yellow", "Green", "Red", "Brown", "Black"};



int main()
{

    enum Color c = Gray;

    printf("%s\n", pcolor[c]);
}


/****************************************************/
/****************************************************/








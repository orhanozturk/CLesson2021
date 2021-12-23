#include <stdio.h>
#include <ctype.h>

int main()
{
    for(int i = 0; i < 128; ++i)
    {
        if(iscntrl(i))
            printf(" %02X     %3d    KONTROL KARAKTERLERI\n", i, i);
        else
            printf(" %02X     %3d    %c\n", i, i, i);
    }

    return 0;
}

/******************************************/
/******************************************/

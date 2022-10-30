#include <stdio.h>


int main()
{

    FILE *f1 = fopen("orhan.txt", "w");
    FILE *f2 = fopen("ozturk.txt", "w");
    FILE *f3 = fopen("mehmet.txt", "w");
    FILE *f4 = fopen("recep.txt", "w");

    ///

    //fclose(f1);
    //fclose(f2);


    int n = _fcloseall();


    printf("%d dosyas kapatildi\n", n);

}


/****************************************************/
/****************************************************/








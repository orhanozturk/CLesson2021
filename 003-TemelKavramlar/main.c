#include <stdio.h>

/*
int main()
{
    int a, b, c;

    a = 5;
    b = 4;

    c = a + b;

    printf("sonuc %d\n", c);

    return 0;
}
*/

/*
int main()
{
    int x;
    //name lookup

    //Derleyici bu ismi algılar
    //Derleyici bu aşamadan önce name  lookup, yani isim arama yapıyor
    //Eğer ismi bulamaz arayıp sentaks hatası olacaktır.

    x = 5;

}
*/


/*
int foo(void);
int main()
{
    foo = 5; // statement
}
*/


/*
int main()
{
    int x = 10;

    &x; //L value

    &(x + 5); // R value

}
*/

int main()
{

    for(int i = 0; i < 128; ++i){
        if(ispunct(i))
            printf("%c ", i);
    }
    printf("\n");

}







#include <stdio.h>
#include <ctype.h>
#include "utility.h"
#include <random>


/*
 * oyun kuralları
 *
 * zarların taoplamı en dusuk 2 en buyuk 12
 *
 * atılan zarların toplamına göre oyuncy ya para kaybetcek ya para kazancak
 *
 * eger zarların 1. atılışında
 * toplam
 *
 * 7 - 11 ise ---> oyuncu kazanır
 * 2 - 3 - 12 ise --> oyuncu kayber kasa kazanır
 * 4 - 5 - 8 - 9 - 10 ise --> oyunun kuralları değişir
 *
 * eger oyunun kuralları değişirse
 * örnek
 * 9 attık ve tekrar 9 atar isek kazandık
 * 5
 * 11
 * 3
 * 8
 * 6
 * 9 eger burada 9 yerine 7 atsaydım kasa kazandı ben kaybettim
 *
 *
 * soru su oyuncunun oyunu kazanma olasılıhı nedir
 * %49,3455   -->  kasıının ki -->%50.23434
 *
 *
 *
 *
 */

#define     NGAMES      1000000

int roll_dice(void)
{
    static std::mt19937 eng;
    static std::uniform_int_distribution<int> dist{1, 6};

    int dice_1 = dist(eng);
    int dice_2 = dist(eng);

    return dice_1 + dice_2;
}

int gameRule(int dice)
{
    while (1) {
        int new_dice = roll_dice();
        if(new_dice == dice)
            return 1;
        if(new_dice == 7)
            return 0;
    }
}

int game(void)
{
    int dice = roll_dice();

    switch (dice) {
    case 7:
    case 11: return 1;
    case 2:
    case 3:
    case 12: return 0;
    default: return gameRule(dice); break;
    }

}

int main()
{
    //randomize();

    int win_count = 0;

    for (int i = 0; i < NGAMES; ++i) {
        win_count += game();
    }

    printf("kazanma olasiligi = %f\n", 100. * win_count / NGAMES);

    return 0;
}

/****************************************************/
/****************************************************/






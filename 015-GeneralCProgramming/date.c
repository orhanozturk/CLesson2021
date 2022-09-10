#include "date.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define         PRIVATE             static
#define         PUBLIC
#define         YEARBASE            1900
#define         RANDOM_YEAR_MIN     1940
#define         RANDOM_YEAR_MAX     2022
#define         day(p)              (p->md)
#define         mon(p)              (p->mm)
#define         year(p)             (p->my)

#define     isleap(y)           ((y) % 4 == 0 && ((y) % 100 || (y) % 400 == 0))
#define     mon_days(y, m)      (daytabs[isleap(y)][m])

const int daytabs[][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

PRIVATE int is_valid_date(int d, int m, int y);
PRIVATE Date * set(Date *p, int d, int m, int y);
PRIVATE int day_of_the_week(int d, int m, int y);
PRIVATE int totaldays(const Date *p);
PRIVATE Date * to_date(Date *p, int tdays);

PUBLIC Date * set_date(Date *p, int d, int m, int y)
{
    return set(p, d, m, y);
}

PUBLIC Date * set_date_today(Date* p)
{
    time_t timer;
    time(&timer);
    struct tm* tptr = localtime(&timer);

    return set(p, tptr->tm_mday, tptr->tm_mon + 1, tptr->tm_year + YEARBASE);
}

PUBLIC Date * set_date_str(Date* p, const char *pstr)
{
    //04-06-1999
    int d = atoi(pstr);
    int m = atoi(pstr + 3);
    int y = atoi(pstr + 6);

    return set(p, d, m, y);
}

PUBLIC Date * set_date_random(Date* p)
{
    int y = rand() % (RANDOM_YEAR_MAX - RANDOM_YEAR_MIN + 1) + RANDOM_YEAR_MIN;
    int m = rand() % 12 + 1;
    int d = rand() % mon_days(y, m) + 1;

    return set(p, d, m, y);
}


PUBLIC Date * set_year(Date *p, int y)
{
    return set(p, day(p), mon(p), y);
}

PUBLIC Date * set_month(Date *p, int m)
{
    return set(p, day(p), m, year(p));
}

PUBLIC Date * set_month_day(Date *p, int d)
{
    return set(p, d, mon(p), year(p));
}

PUBLIC int get_year(const Date* p)
{
    return year(p);
}

PUBLIC int get_month(const Date* p)
{
    return mon(p);
}

PUBLIC int get_month_day(const Date* p)
{
    return day(p);
}

PUBLIC int get_week_day(const Date* p)
{
    return day_of_the_week(day(p), mon(p), year(p));
}

PUBLIC int get_year_day(const Date* p)
{
    int sum  = day(p);

    for(int i = 1; i < mon(p); ++i){
        sum += mon_days(year(p), i);
    }

    return sum;
}


PUBLIC void print_date(const Date * p)
{
    static const char *const pmons[] = {
        "",
        "Ocak",
        "Subat",
        "Mart",
        "Nisan",
        "Mayis",
        "Haziran",
        "Temmuz",
        "Agustos",
        "Eylul",
        "Ekim",
        "Kasim",
        "Aralik"
    };

    static const char * const pdays[] = {
        "Pazar",
        "Pazartesi",
        "Sali",
        "Carsamba",
        "Persembe",
        "Cuma",
        "Cumartesi",
    };

    printf("%02d %s %d %s\n", day(p), pmons[mon(p)], year(p), pdays[get_week_day(p)]);
}

PUBLIC Date * scan_date(Date *p)
{
    int d, m, y;

    scanf("%d%d%d", &d, &m, &y);
    return set(p, d, m, y);
}

PUBLIC int cmp_date(const Date*p1, const Date *p2)
{
    if(year(p1) != year(p2)){
        return (year(p1) - year(p2));
    }

    if(mon(p1) != mon(p2)){
        return (mon(p1) - mon(p2));
    }

    return day(p1) - day(p2);
}

PUBLIC int date_diff(const Date *p1, const Date *p2)
{
    return abs(totaldays(p1) - totaldays(p2));
}

PUBLIC Date *ndays_date(Date *pdest, const Date* psource, int n)
{
    return to_date(pdest, totaldays(psource) + n);
}

PRIVATE int is_valid_date(int d, int m, int y)
{
    return  y >= YEARBASE &&
            m > 0 && m <= 12 &&
            d > 0 && d <= mon_days(y, m);
}

PRIVATE Date * set(Date *p, int d, int m, int y)
{
    if(!is_valid_date(d, m, y)){
        fprintf(stderr, "gecersiz tarih olstur!\n");
        exit(EXIT_FAILURE);
    }

    p->md = d;
    p->mm = m;
    p->my = y;

    return p;
}

// function to implement tomohiko
// sakamoto algorithm
PRIVATE int day_of_the_week(int d, int m, int y)
{
    // array with leading number of days values
    const static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

    // if month is less than 3 reduce year by 1
    if (m < 3)
        y -= 1;

    return ((y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7);
}

PRIVATE int totaldays(const Date *p)
{
    int sum = get_year_day(p);

    for(int i = YEARBASE; i < year(p); ++i){
        sum += isleap(i) ? 366 : 365;
    }

    return sum;

}

PRIVATE Date * to_date(Date *p, int tdays)
{
    int y = YEARBASE;

    while(tdays > (isleap(y) ? 366 : 365)){
        tdays -= (isleap(y) ? 366 : 365);
        ++y;
    }

    int m = 1;

    while(tdays > mon_days(y, m)){
        tdays -= mon_days(y, m);
        ++m;
    }

    int d = tdays;

    return set(p, d, m, y);
}





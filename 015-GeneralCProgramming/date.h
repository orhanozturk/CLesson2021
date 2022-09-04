#ifndef DATE_H
#define DATE_H

//pragma ilede aynı guvenlık saglanır

typedef struct{
    void *vp;
}Date;


//setters
//mutaturs
//set functions
Date * set_date(Date *, int d, int m, int y);
Date * set_date_today(Date*);
Date * set_date_str(Date*, const char *pstr);
Date * set_date_random(Date*);
Date * set_year(Date *p, int y);
Date * set_month(Date *p, int m);
Date * set_month_day(Date *p, int d);


//getters
//get functions
//accessors

int year(const Date*);
int month(const Date*);
int month_day(const Date*);
int week_day(const Date*);
int year_day(const Date*);


//formatted input_output functions
void print_date(const Date *);
void scan_date(Date *p);

//utility functions
Date *ndays_date(Date *dest, const Date* psource, int n);
int date_diff(const Date *p1, const Date *p2);
int cmp_date(const Date*p1, const Date *p2);














#endif // DATE_H

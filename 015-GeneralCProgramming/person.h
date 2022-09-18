#ifndef PERSON_H
#define PERSON_H

#include "date.h"

typedef struct {
    int m_id;
    char m_name[20];
    char m_surname[24];
    char m_town[20];
    Date m_bdate;

}Person;

Person* set_person_random(Person *);
void print_person(const Person *);
int cmp_person(const Person *p1, const Person *p2);
void print_person_to_file(FILE *f, const Person *);

#endif // PERSON_H

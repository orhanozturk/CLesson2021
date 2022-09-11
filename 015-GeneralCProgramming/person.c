#include "person.h"
#include "utility.h"

Person* set_person_random(Person * p)
{

    p->m_id = rand() * rand() % 50000;
    strcpy(p->m_name, random_name());
    strcpy(p->m_surname, random_surname());
    strcpy(p->m_town, random_town());
    set_date_random(&p->m_bdate);

    return p;
}

void print_person(const Person *p)
{
    printf("%-6d %-18s %-24s %-16s", p->m_id, p->m_name, p->m_surname, p->m_town);
    print_date(&p->m_bdate);
}

int cmp_person(const Person *p1, const Person *p2)
{
    int cmp_result = strcmp(p1->m_surname, p2->m_surname);
    if(cmp_result)
        return cmp_result;

    cmp_result = strcmp(p1->m_name, p2->m_name);
    if(cmp_result)
        return cmp_result;

    cmp_result = strcmp(p1->m_town, p2->m_town);
    if(cmp_result)
        return cmp_result;

    cmp_result = cmp_date(&p1->m_bdate, &p2->m_bdate);
    if(cmp_result)
        return cmp_result;

    return p1->m_id - p2->m_id;
}

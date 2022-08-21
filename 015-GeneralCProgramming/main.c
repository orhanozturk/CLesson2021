#include <stdio.h>
#include "utility.h"
#include <string.h>

typedef struct Employee{
    int id;
    char name[20];
    char surname[30];
    double wage;
}Employee;


//typedef struct Employee Employee;

void set_employee(Employee *e) //setter
{
    e->id = 123123;
    e->wage = 111.;
    _strupr(e->name);
    _strupr(e->surname);
}


void print_employee(const Employee *e) //getter
{
    printf("%d  %s  %s  %.2f\n", e->id, e->name, e->surname, e->wage);
}

int main()
{
    struct Employee emp = {20, "orhan", "ozturk", 45.3};

    printf("%d  %s  %s  %.2f\n", emp.id, emp.name, emp.surname, emp.wage);
    set_employee(&emp);//call by reference
    print_employee(&emp);//call by reference

}


/****************************************************/
/****************************************************/








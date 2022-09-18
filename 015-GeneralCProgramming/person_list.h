#ifndef PERSON_LIST_H
#define PERSON_LIST_H

#include "person.h"

struct List;
typedef struct List* ListHandle;

ListHandle create_list(void);
void destroy_list(ListHandle);
void push_front(ListHandle, const Person *p);
void pop_front(ListHandle);
size_t get_size(ListHandle);
int is_empty(ListHandle);
void print_list(ListHandle);
void make_empty(ListHandle);
void get_first(ListHandle, Person *p);


#endif // PERSON_LIST_H

#include "person_list.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    Person per;//data
    struct Node* pnext;
}Node;

struct List{
    Node* pfirst;
    size_t count;
};


ListHandle create_list(void)
{
    ListHandle pd = (ListHandle)malloc(sizeof (struct List));

    if(!pd){
        return NULL;
    }

    pd->pfirst = NULL;
    pd->count = 0;

    return pd;
}

Node * create_node(void)
{
    Node * pd = (Node *)malloc(sizeof (Node));
    if(!pd){
        fprintf(stderr, "bellek yetersiz\n");
        exit(EXIT_FAILURE);
    }

    return pd;
}

void destroy_list(ListHandle h)
{
    make_empty(h);

    free(h);
}

size_t get_size(ListHandle h)
{
    return h->count;
}

int is_empty(ListHandle h)
{
    //return count == 0;
    return h->pfirst == NULL;
}

void print_list(ListHandle h)
{
    for (Node *p = h->pfirst; p != NULL; p = p->pnext) {
        print_person(&p->per);
    }

    printf("****************************************\n");
}


void push_front(ListHandle h, const Person *p)
{
    Node * p_new_node = create_node();

    p_new_node->per = *p;
    p_new_node->pnext = h->pfirst;
    h->pfirst = p_new_node;
    h->count++;

}

void pop_front(ListHandle h)
{
    if(is_empty(h)){
        printf("bos liste hatasi\n");
        exit(EXIT_FAILURE);
    }

    Node *ptemp = h->pfirst;
    h->pfirst = h->pfirst->pnext;
    free(ptemp);
    --h->count;
}

void make_empty(ListHandle h)
{
    while (!is_empty(h)) {
        pop_front(h);
    }
}

void get_first(ListHandle h, Person *p)
{
    if(is_empty(h)){
        printf("bos liste hatasi\n");
        exit(EXIT_FAILURE);
    }

    *p = h->pfirst->per;
}















#include <stdio.h>
#include "utility.h"
#include <string.h>
#include <ctype.h>

#define     SIZE        100

int main()
{
    const char *p[] = {
        "orhan",         "esma",          "busra",         "azize",         "ahmet",        "nermin",        "cemile",
        "naciye",       "meryem",          "sergen",        "cengiz",       "negun",        "melise",          "mahmur",
        "halis",        "recep",            "sema",         "elif",         "murat",        "melike",          "rumeysa",
        "okan",         "kazim",          "neriman",        "aysun",        "kemal",        "hacer",           "muhammed",
        "nuran",        "fatma",           "engin",         "fikret",       "musatafa",      "yusuf",            "omer",
    };


    int c;
    printf("bir karater girin :");
    c = getchar();

    for (size_t i = 0; i < asize(p); ++i) {
        //if(strchr(p[i], c) != NULL)
          if(strchr(p[i], c))
            printf("%s  ", p[i]);
    }

}


/****************************************************/
/****************************************************/









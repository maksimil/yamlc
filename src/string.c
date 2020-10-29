#include "yamlc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void yc_initialize_string(yc_string *string, char *data)
{
    string->allocated = strlen(data) + 1;
    string->data = malloc(string->allocated);
    if (string->data == NULL)
    {
        printf("Memory allocation failed");
        return;
    }

    strcpy_s(string->data, string->allocated, data);
}

void yc_destroy_string(yc_string *string)
{
    free(string->data);
}

void yc_set_string(yc_string *string, char *data)
{
    size_t nsize = strlen(data) + 1;
    if (nsize > string->allocated)
    {
        char *nptr = realloc(string->data, nsize);
        if (nptr == NULL)
        {
            printf("Memory allocation failed");
            return;
        }

        string->allocated = nsize;
        string->data = nptr;
    }

    strcpy_s(string->data, string->allocated, data);
}
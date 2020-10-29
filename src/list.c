#include "yamlc.h"
#include <stdlib.h>

void yc_initialize_list(yc_list *list, size_t size)
{
    list->allocated = size;
    list->size = 0;
    list->data = malloc(size * sizeof(yc_object));
}

void yc_destroy_list(yc_list *list)
{
    for (size_t i = 0; i < list->size; i++)
    {
        yc_destroy_object(&list->data[i]);
    }

    free(list->data);
}

yc_object *yc_push(yc_list *list, char *name)
{
    if (list->size == list->allocated)
    {
        void *nptr = realloc(list->data, list->allocated * 2);
        if (nptr == NULL)
            return NULL;
        list->data = nptr;
        list->allocated *= 2;
    }

    yc_object *object = &list->data[list->size++];
    yc_initialize_object(object, name);

    return object;
}
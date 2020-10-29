#include "yamlc.h"
#include <stdio.h>
#include <string.h>

void yc_indent_file(FILE *file, uint8_t amount)
{
    char *indent = malloc(amount + 1);
    memset(indent, 32, amount);
    indent[amount] = 0;

    fprintf(file, indent);

    free(indent);
}

void yc_write_child(yc_object *object, FILE *file, uint8_t indent)
{
    switch (object->child_type)
    {
    case string_type:
        fprintf(file, "%s\n", ((yc_string *) object->child)->data);
        break;
    case object_type:
    {
        if (object->root != NULL)
            fprintf(file, "\n");

        yc_list *list = object->child;
        for (size_t i = 0; i < list->size; i++)
        {
            yc_indent_file(file, indent);
            fprintf(file, "%s: ", list->data[i].name.data);
            yc_write_child(&list->data[i], file, indent + 2);
        }
        break;
    }
    }
}

void yc_write_file(yc_emitter *emitter, FILE *file)
{
    yc_write_child(&emitter->root, file, 0);
}
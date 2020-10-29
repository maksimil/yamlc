#include "yamlc.h"

void yc_initialize_object(yc_object *object, char *name)
{
    yc_initialize_string(&object->name, name);

    object->child = NULL;
    object->child_type = none;

    object->root = NULL;
}

void yc_destroy_object(yc_object *object)
{
    yc_destroy_string(&object->name);

    switch (object->child_type)
    {
    case none:
        break;

    case string:
        yc_destroy_string(object->child);
        break;

    case list:
    case map:
        yc_destroy_list(object->child);
        break;
    }
}
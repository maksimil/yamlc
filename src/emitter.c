#include "yamlc.h"
#include <stdlib.h>

void yc_initialize_emitter(yc_emitter *emitter)
{
    yc_initialize_object(&emitter->root, "");
    emitter->current = &emitter->root;
}

void yc_destroy_emitter(yc_emitter *emitter)
{
    yc_destroy_object(&emitter->root);
}

void yc_close(yc_emitter *emitter)
{
    emitter->current = emitter->current->root;
}

void yc_set_value(yc_emitter *emitter, char *value)
{
    emitter->current->child_type = string_type;
    emitter->current->child = malloc(sizeof(yc_string));

    yc_initialize_string(emitter->current->child, value);

    yc_close(emitter);
}

void yc_set_object(yc_emitter *emitter)
{
    emitter->current->child_type = object_type;
    emitter->current->child = malloc(sizeof(yc_list));

    yc_initialize_list(emitter->current->child, 2);
}

void yc_add_property(yc_emitter *emitter, char *name)
{
    yc_object *object = yc_push(emitter->current->child, name);
    object->root = emitter->current;

    emitter->current = object;
}
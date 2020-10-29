#ifndef __H_YAML_C
#define __H_YAML_C

#include <stdint.h>

typedef enum yc_type
{
    none,
    string,
    list,
    map
} yc_type;

typedef struct yc_string
{
    char *data;
    size_t allocated;
} yc_string;

typedef struct yc_object
{
    yc_string name;

    void *child;
    yc_type child_type;

    struct yc_object *root;
} yc_object;

typedef struct yc_list
{
    yc_object *data;
    size_t size;
    size_t allocated;
} yc_list;

typedef struct yc_emitter
{
    yc_object root;
    yc_object *current;
} yc_emitter;

// string functions
void yc_initialize_string(yc_string *, char *);
void yc_set_string(yc_string *, char *);
void yc_destroy_string(yc_string *);

// object functions
void yc_initialize_object(yc_object *, char *name);
void yc_destroy_object(yc_object *);

// list functions
void yc_initialize_list(yc_list *, size_t);
void yc_destroy_list(yc_list *);
yc_object *yc_push(yc_list *);

// emitter functions
void yc_initialize_emitter(yc_emitter *);
void yc_destroy_emitter(yc_emitter *);

void yc_add_property(yc_emitter, char *);

void yc_set_object(yc_emitter *);
void yc_set_value(yc_emitter *, char *);

void yc_close(yc_emitter *);

// file functions
void yc_read_file(yc_object *, char *);
void yc_write_file(yc_object *, char *);
#endif
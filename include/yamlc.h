#include <stdint.h>

// object type
typedef enum
{
    // yc_string
    string,
    // yc_list of yc_pairs
    dictionary,
    // yc_list of yc_objects
    list
} yc_type;

// object, which could be string, dictionary or list
typedef struct
{
    void *object;
    yc_type type;
} yc_object;

// string
typedef char *yc_string;

// pair of key and value
typedef struct
{
    yc_string key;
    yc_object value;
} yc_pair;

// list of values
typedef struct
{
    void **data;
    size_t size;
    size_t allocated;
} yc_list;

// list functions
yc_list *yc_create_list();
yc_list *yc_create_list(size_t);
void yc_create_list(yc_list *);
void yc_create_list(yc_list *, size_t);
void yc_destroy_list(yc_list *);

// pushes element to list
void yc_push_el(yc_list *, void *);
// pushes key-value pair to dictionary
void yc_push_kw(yc_list *, yc_string, yc_object);

// object functions
yc_object *yc_create_object(yc_type);
void yc_create_object(yc_object *, yc_type);
void yc_destroy_object(yc_object *);

// file functions
void yc_write_file(yc_string, yc_object *);
void yc_read_file(yc_string, yc_object *);
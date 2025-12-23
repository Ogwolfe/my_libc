#ifndef MY_ALLOCATOR_H
#define MY_ALLOCATOR_H

#include <stddef.h>

typedef struct Header{
    unsigned int is_free;
    size_t len;
    struct Header *next;
} Header;

void *my_malloc(size_t size);


#endif
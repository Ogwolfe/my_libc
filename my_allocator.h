#ifndef MY_ALLOCATOR_H
#define MY_ALLOCATOR_H

#include <stddef.h>

typedef struct Block{
    unsigned int is_free;
    size_t len;
    struct Block *next;
} Block;

void *my_malloc(size_t size);
Block *search_free_blocks(size_t size);


#endif
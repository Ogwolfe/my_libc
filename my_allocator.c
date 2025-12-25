#include "my_allocator.h"
#include <unistd.h>

Block *head = NULL, *tail = NULL;

void *my_malloc(size_t size){

    if(size == 0) return NULL;

    //Check for an available block
    Block *p = search_free_blocks(size);
    if(p){
        p->is_free = 0; //Mark as used
        return (void *)(p + 1);
    }
    
    //Case: Empty list. Insert first block
    if(tail == NULL){
        size_t total_size = (sizeof( struct Block) + size);
        void *block = sbrk(total_size);
        head = block;
        tail = block;
        tail->next = NULL;
        tail->len = size;
        tail->is_free = 0;
    }

    else {
        size_t total_size = (sizeof (struct Block) + size);
        
        void *block = sbrk(total_size);
        if (block == (void *)-1) return NULL;

        tail->next = (Block *)block;
        tail = tail->next;
        tail->next = NULL;
        tail->len = size;
        tail->is_free = 0;
    }

    return (void *) (tail + 1);
}

Block *search_free_blocks(size_t size){
    Block *p = head;
    while(p != NULL){
        if(p->is_free && p->len >= size){
            return p;
        }
        
        p = p->next;
    }

    return p;
}
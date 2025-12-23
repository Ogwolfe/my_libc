#include "my_libc.h"

//Return the length of a c string
unsigned int my_strlen(const char *s){
    unsigned len = 0;
    while(*s != '\0'){
        len++;
        s++;
    }
    return len;
}

//Copy the bytes from src into dest
//User responsible for ensuring dest is large enough to hold the bytes from src
char *my_stpcpy(char *restrict dest, const char *restrict src){
    while((*dest++ = *src++) != '\0');
    return dest;
}

char *my_strcpy(char *d, const char *s){
    my_stpcpy(d, s);
    return d;
}

int my_strncmp(const char *str1, const char *str2, size_t len){
    while(len > 0 && *str1 == *str2 && *str1 != '\0'){
        len--;
        str1++;
        str2++;
    }
    if(len == 0) return 0;
    return (*str1 - *str2);
}

void *my_memcpy(void *restrict dest, const void *restrict src, size_t n){
    unsigned char *d = (unsigned char*) dest;
    const unsigned char *s = (const unsigned char*) src;
    for(; n > 0; n--, d++, s++){
        *d = *s;
    }
    return dest;
}

void *my_memmove(void *dest, const void *src, size_t n){

    unsigned char *d = (unsigned char*) dest;
    const unsigned char *s = (const unsigned char*) src;

    if(dest <= src){
        for(; n > 0; n--, d++, s++){
            *d = *s;
        }
    }
    else{
        d += n - 1;
        s += n - 1;

        for(; n > 0; n--, d--, s--){
            *d = *s;
        }
    }
    
    return dest;
}

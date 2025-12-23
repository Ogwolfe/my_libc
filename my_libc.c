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
    int diff = 0;
    while(*str1 != '\0' && len-- > 0){
        if((diff = (*str1++ - *str2++)) != 0) return diff;
    }

    return diff;
}
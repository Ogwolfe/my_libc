#ifndef MY_LIBC_H
#define MY_LIBC_H

#include <stddef.h>

unsigned int my_strlen(const char *s);
char *my_strcpy(char *restrict dest, const char *restrict src);
char *my_strcpy(char *d, const char *s);
int my_strncmp(const char *str1, const char *str2, size_t len);
void *my_memcpy(void *restrict dest, const void *restrict src, size_t n);
void *my_memmove(void *dest, const void *src, size_t n);

#endif
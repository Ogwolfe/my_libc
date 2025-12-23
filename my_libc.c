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
char *my_strcpy(char *restrict dest, char *restrict src){
    while(*src) *dest++ = *src++;
    *dest = '\0';
    return dest;
}
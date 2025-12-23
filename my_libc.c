//Return the length of a c string
int my_strlen(const char *s){
    int len = 0;

    //Check if the pointer is valid
    if(!s){
        //Invalid pointer
        return -1;
    }

    //While the pointer is valid, increment length and the pointer until it points to '\0'
    while(*s != '\0'){
        len++;
        s++;
    }

    return len;
}
//Return the length of a c string
int my_strlen(const char *s){
    int len = 0;

    //Check if the pointer is valid
    if(!s){
        //Invalid pointer
        return -1;
    }

    //While the pointer is valid, increment length and the pointer until it's NULL
    while(s){
        len++;
        s++;
    }

    return len;
}
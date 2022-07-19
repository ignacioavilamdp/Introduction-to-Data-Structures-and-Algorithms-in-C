#include <stdio.h>

/* Shows a simple function to the lowercase of a char  */

char lowerCase(char c){
    if ((c >= 'A') && (c <= 'Z'))
        return c + 'a' - 'A';
    else
        return c;
}

int main(){
    char c;

    printf("Write a character: ");
    c = getchar();

    c = lowerCase(c);
    printf("In lowercase: %c", c);

    return 0;
}



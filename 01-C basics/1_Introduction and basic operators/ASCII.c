#include <stdio.h>

/* Prints ASCII code without the first 31 control characters */

int main(){

    for (int i = 32; i < 128; i++){
        printf("%i %c \n", i, i);
    }

    return 0;
}

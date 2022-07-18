#include <stdio.h>

/* Counts how may bits of an unsigned integer are in high value (1) */

int bitcount(unsigned int x){
    int b;
    for (b = 0; x != 0; x >>= 1){
        if (x & 01)
            b++;
    }
    return b;
}

int main(){
    unsigned int x = 0;
    unsigned int b = 0;

    printf("Enter a number: ");
    scanf("%u", &x);
    printf("This number has %u bits with value of 1 \n\n", bitcount(x));

    return 0;
}



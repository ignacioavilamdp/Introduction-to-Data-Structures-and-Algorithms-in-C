#include <stdio.h>

/* Inverts (complements or flips) the first n bits of x */

int invert(int x, int n){
    int k, t, l, xr, xl, r;

    k = ~0;       // word with every bit in 1 (example: 1111 1111)
    t = k << n;   // right shifts n bits of k (example n=3: 1111 1000). this leaves a mask of "1" to the left of the first n bits
    l = ~t;       // one's complement of t (example n=3: 0000 0111). this leaves a mask of "1" on the first n bits

    xl = x & t;   // filters x through the first mask
    xr = ~x & l;  // filters the complement of x through the second mask
    r = xl + xr;  // Final result

    return r;
}

int main(){
    int x, n, r;

    printf("x: "); scanf("%d", &x);
    printf("d: "); scanf("%d", &n);
    printf("inverted: %d", invert(x, n));

    return 0;
}


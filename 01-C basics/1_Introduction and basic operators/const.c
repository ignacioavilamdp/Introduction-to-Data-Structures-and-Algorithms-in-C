#include <stdio.h>

/* Shows that a variable declared with the "const" qualifier cannot be changed: compilation error */

int main(){
    const int x = 1;
    x = 3;   //Fail

    return 0;
}

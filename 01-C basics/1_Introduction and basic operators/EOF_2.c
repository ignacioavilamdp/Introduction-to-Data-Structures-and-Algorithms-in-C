#include <stdio.h>

/*  The typical way to generate an EOF from the Windows command prompt is "Crtl + Z" or "Ctrl + C" */

int main(){
    int i;
    i = getchar();
    while (i != EOF){
        i = getchar();
    }
    return 0;
}

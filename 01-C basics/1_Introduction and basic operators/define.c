#include <stdio.h>
#define A 25
#define SUM x + y
#define DIFFERENCE x - y
#define MAX(x,y) ((x > y) ? x : y)

/*
 * The #define directive to the preprocessor allows to replace a symbol with an arbitrary sequence of characters (K&R 4.11)
 * In general, "#define name text" tells the preprocessor to replace any occurrence of "name" with "text".
 * The replacement takes place, of course, previous to compilation.
 * A typical use of this directive is to create symbolic constants or macros.
 */

int main(){
    int x, y;

    printf("x: "); scanf("%d", &x);
    printf("y: "); scanf("%d", &y);

    printf("A: %d \n",A);
    printf("x + y: %d \n", SUM);
    printf("x - y: %d \n", DIFFERENCE);
    printf("The greater is: %d \n", MAX(x, y));

    return 0;
}

#include <stdio.h>

int bitAnd(int x, int y);

int main() {
int x = 9;
int y = 3;
int z = bitAnd(x, y);
printf("z = %d\n", z);

    return 0;
}



/*
* bitAnd ‐ x&y using only ~ and |
* Example: bitAnd(6, 5) = 4
* Legal ops: ~ |
* Max ops: 8
* Rating: 1
*/
int bitAnd(int x , int y) {
    return ~(~x | ~y);
}


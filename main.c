#include <stdio.h>

int bitAnd(int x, int y);
int getByte(int x, int n);
int logicalShift(int x, int n);

int main() {
    int x=0x12345678;
    int n=16;

    printf("%x\n", logicalShift(x,n));
    printf("%x\n", x>>n);

    return 0;
}


/*
* bitAnd ‐ x&y using only ~ and |
* Example: bitAnd(6, 5) = 4
* Legal ops: ~ |
* Max ops: 8
* Rating: 1
*/
int bitAnd(int x, int y) {
    return ~(~x|~y);
}

/*
* getByte ‐ Extract byte n from word x
* Bytes numbered from 0 (LSB) to 3 (MSB)
* Examples: getByte(0x12345678,1) = 0x56
* Legal ops: ! ~ & ^ | + << >>
* Max ops: 6
* Rating: 2
*/
int getByte(int x, int n) {
    int y=n<<3;
    x>>=y;
    int mask=~1;
    mask<<=8;

    return x&(~mask);
}

int logicalShift(int x, int n){
    int mask = ~((~1)<<(31 + (~n + 1)));
    x>>=n;
    return x&mask;
}
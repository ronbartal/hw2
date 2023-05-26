
/*
* bitAnd ‐ x&y using only ~ and |
* Example: bitAnd(6, 5) = 4
* Legal ops: ~ |
* Max ops: 8
* Rating: 1
*/

int bitAnd(int x, int y) {
    /* De Morgan's law: ~(~x|~y) = x&y */
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

    /* extract the bits from the byte we want and shift x to the right */
    /* accordingly. then, by using mask to get rid of the rest of the */
    /* bits, we get the byte we want. */

    int y=n<<3;
    x>>=y;
    int mask=~1;
    mask<<=8;

    return x&(~mask);
}

/*
* logicalShift ‐ shift x to the right by n, using a logical shift
* Can assume that 0 <= n <= 31
* Examples: logicalShift(0x87654321,4) = 0x08765432
* Legal ops: ! ~ & ^ | + << >>
* Max ops: 20
* Rating: 3
*/

int logicalShift(int x, int n){

   /* creating a mask with 1's in the left n bits and 0's in the rest */
    /* then, shifting x to the right n times and 'zero' the left n bits */

    int mask = ~((~1)<<(31 + (~n + 1)));
    x>>=n;
    return x&mask;
}
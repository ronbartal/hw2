//
// Created by ronba on 5/18/2023.
//
#include <stdio.h>
#include <limits.h>

unsigned float_neg(unsigned uf);

int main() {
    unsigned uf= 1;
    printf("%u", float_neg(uf));
    return 0;
}

/**
 * if f is the value of uf in float represetion, convert to -f
 * @param uf
 * @return unsigned that express -f if read as float
 */
unsigned float_neg(unsigned uf){
    // mask to check if NaN
    int mask= (1<<31); // 1 0..0 0..0
    mask >>= 8;// 1 111...1 0000..0
    int mask_2 = mask ^ (1<<31); //0 111..11 0.00000
    if (!((uf^mask) && (uf^mask_2))){
        printf("NaN\n");
        return uf;
    }

    mask= 1<<31; // 1000...0
    return uf ^ mask;

    //unsigned mask= 1<<31; // crate a mask: 10000...00
    //uf += mask; // if msb (signbit later) == 0 --> 0+1=1, if msb == 1 --> 1+1 = 10 --> 0 because of overflow
    return uf;
}
/**
 * mask := 10000...000
 * if uf>0 lets say := 0 ee...ee ff...f --> 1 ee...e f...f
 * if uf<0 lets say := 1 ee...ee ff...f --> 0 ee...e f...f
 *
 * unsigned x=17;
 * float y=(float)x;
 * unsigned z= (unsigned)y
 * (z==x);
 */

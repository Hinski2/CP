#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void wypisz(uint64_t x){
    for(int64_t i = 63; i >= 0; i--)
        printf("%d", (x & (1LL << i)) >= 1);
    printf("\n");
}

int cnt(uint64_t x){
    const uint64_t m1  = 0x5555555555555555; //binary: 0101...
    const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
    const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
    const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
    const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...
    const uint64_t m32 = 0x00000000ffffffff; //binary: 32 zeros, 32 ones

    uint64_t y = x;
    
    y = x;
    y >>= 1;
    y &= m1;
    x &= m1;
    x <<= 1;
    x |= y;

    y = x;
    y >>= 2;
    y &= m2;
    x &= m2;
    x <<= 2;
    x |= y;

    y = x;
    y >>= 4;
    y &= m4;
    x &= m4;
    x <<= 4;
    x |= y;

    y = x;
    y >>= 8;
    y &= m8;
    x &= m8;
    x <<= 8;
    x |= y;

    y = x;
    y >>= 16;
    y &= m16;
    x &= m16;
    x <<= 16;
    x |= y;

    y = x;
    y >>= 32;
    y &= m32;
    x &= m32;
    x <<= 32;
    x |= y;

    wypisz(x);
    return x;
}

int main(){
    uint64_t x;scanf("%ld", &x);
    cnt(x);
}
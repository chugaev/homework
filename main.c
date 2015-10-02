#include <stdio.h>

int bitAnd(int x, int y) {
    return ~(~x | ~y);
}

int bitXor(int x, int y) {
    return ~(~(x & ~y) & ~(~x & y));
}

int thirdBits() {
    int a = (0x24 << 24) | (0x92 << 16);
    int b = (0x49 << 8) | (0x24);
    return a|b;
}

int sign(int x) {
    return (x >> 31) | !!(x & (~0));
}

int getByte(int x, int n) {
    return (x >> (n << 3)) & 255;
}

int fitBits(int x, int n) {
    return !((x ^ (x >> 31)) >> (n + (~0)));
}
int logicalShift(int x, int n) {
    int a = 1 << 31;
    int b = a & x;
    b >>= 31;
    b &= 1;
    b <<= (31  + (~n + 1));
    x &= ~a;
    x >>= n;
    return x | b;

}

/*int addOK(int x, int y) {

}

int bang(int x) {

}*/

int conditional(int x, int y, int z) {
    x = !!x;
    x |= x << 1;
    x |= x << 2;
    x |= x << 4;
    x |= x << 8;
    x |= x << 16;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return (x & y) | (~x & z);
}

int isPower2(int x) {
    return !(x & (x + ~0)) | !x;
}

int main(void)
{
    int x = 0xFFFFFFFF, n = 16;
    printf("%x", logicalShift(x, n));
    return 0;
}


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

int logicalShift(int x, int n) {

}

int addOK(int x, int y) {

}

int bang(int x) {

}

int conditional(int x, int y, int z) {

}

int isPower2(int x) {
    return !(x & (x - 1)) | !x;
}
int main(void)
{
    int a;
    scanf("%d", &a);
    printf("%o", isPower2(a)) ;
    return 0;
}


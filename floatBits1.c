#include <stdio.h>

void floatBits1(float number) {
    union {
        float f;
        int i;
    } x;
    x.f = number;
    int sign = (x.i >> 31) & 1;
    int exp = (x.i >> 23) & 0xff;
    int man = x.i & 0x7fffff;
    printf("%d %d %d\n", sign, exp, man);
}

int main(void)
{
    float f;
    scanf("%f", &f);
    floatBits1(f);
    return 0;
}



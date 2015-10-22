#include <stdio.h>

void floatBits2(float number) {
    union {
        float f;
        struct {
            unsigned int man : 23;
            unsigned int exp : 8;
            unsigned int sign : 1;
        } bit;
    } x;
    x.f = number;
    int sign = x.bit.sign;
    int exp = x.bit.exp;
    int man = x.bit.man;
    printf("%d %d %d\n", sign, exp, man);
}

int main(void)
{
    float f;
    scanf("%f", &f);
    floatBits2(f);
    return 0;
}



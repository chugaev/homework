#include <stdio.h>

void print_float(int sign, int exp, int man) {
    int e = exp - 127;
    float m = (float) man / (float) 0x800000 + 1;
    if (exp == 0xff) {
        if (man) {
            printf("NaN\n");
        } else {
            printf((sign ? "-inf\n" : "+inf\n"));
        }
    } else {
        printf("(-1)^%d * 2^(%d) * %f\n", sign, e, m);
    }
}

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
    print_float(sign, exp, man);
}

int main(void)
{
    float f1, f2;
    scanf("%f%f", &f1, &f2);
    floatBits2(f1 / f2);
    return 0;
}



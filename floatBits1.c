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

void floatBits1(float number) {
    union {
        float f;
        int i;
    } x;
    x.f = number;
    int sign = (x.i >> 31) & 1;
    int exp = (x.i >> 23) & 0xff;
    int man = x.i & 0x7fffff;
    print_float(sign, exp, man);
}

int main(void)
{
    float f1, f2;
    scanf("%f%f", &f1, &f2);
    floatBits1(f1 / f2);
    return 0;
}



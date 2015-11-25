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

void floatBits3(float number) {
    int *p = (int *) (&number);
    int sign = (*p >> 31) & 1;
    int exp = (*p >> 23) & 0xff;
    int man = *p & 0x7fffff;
    print_float(sign, exp, man);
}

int main(void)
{
    float f1, f2;
    scanf("%f%f", &f1, &f2);
    floatBits3(f1 / f2);
    return 0;
}



#include <stdio.h>

void floatBits3(float number) {
    int *p = (int *) (&number);
    int sign = (*p >> 31) & 1;
    int exp = (*p >> 23) & 0xff;
    int man = *p & 0x7fffff;
    printf("%d %d %d\n", sign, exp, man);
}

int main(void)
{
    float f;
    scanf("%f", &f);
    floatBits3(f);
    return 0;
}



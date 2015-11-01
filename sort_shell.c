#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int* mas = (int*)malloc(sizeof(int) * n);
    int i;
    for(i = 0; i < n; i++) {
      scanf("%d", &mas[i]);
    }

    int s = -1;
    int* inc = (int*)malloc(sizeof(int) * 40);
    do {
        if (++s % 2) {
            inc[s] = 8 * (1 << s) - 6 * (1 << (s / 2)) + 1;
        } else {
            inc[s] = 9 * (1 << s) - 9 * (1 << ((s + 1) / 2)) + 1;
        }
    } while( 3 * inc[s] < n);

    int j, d;
    for(d = inc[s]; d > 0; d = inc[s--]) {
        for(i = d; i < n; i++) {
            for(j = i; j >= d && mas[j - d] > mas[j]; j -= d) {
                int temp = mas[j];
                mas[j] = mas[j - d];
                mas[j - d] = temp;
            }
        }
    }
    for(i = 0; i < n; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");

    printf("work time:%f\n", (double) clock() / CLOCKS_PER_SEC);

    return 0;
}

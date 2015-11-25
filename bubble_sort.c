#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int MAX_NUMBER = 100000;
    int n ;
    scanf("%d", &n);
    int* mas = (int*)malloc(sizeof(int) * n);
    if (mas == 0) {
        printf("Memory allocation error\n");
        return 0;
    }
    clock_t start_time = clock();
    int i;
    for (i = 0; i < n; i++) {
        mas[i] = rand() % MAX_NUMBER;
    }
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++) {
        printf("%d ", mas[i]);
    }
    clock_t finish_time = clock();

    printf("\n");

    printf("work time:%f\n", (double) (finish_time - start_time) / CLOCKS_PER_SEC);
    free(mas);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    const int MAX_NUMBER = 100000;
    const int SIZE = 40;
    int n;
    scanf("%d", &n);
    int* mas = (int*)malloc(sizeof(int) * n);
    int* inc = (int*)malloc(sizeof(int) * SIZE);
    if (inc == 0 || mas == 0) {
        printf("Memory allocation error\n");
        return 0;
    }
    int i;
    for (i = 0; i < n; i++) {
        mas[i] = rand() % MAX_NUMBER;
    }
    /*
     * Расчет приращений шелла методом Р. Седжвика
     * Форумлы:
     * d[i] = 9 * 2i - 9 * 2 ^ (i/2) + 1, если i четно
     * d[i] = 8 * 2i - 6 * 2 ^ ((i+1) / 2) + 1, если i нечетно
     * Источник: https://ru.wikipedia.org/wiki/Сортировка_Шелла
     */
    int s = -1;
    do {
        if (++s % 2) {
            inc[s] = 8 * (1 << s) - 6 * (1 << (s / 2)) + 1;
        } else {
            inc[s] = 9 * (1 << s) - 9 * (1 << ((s + 1) / 2)) + 1;
        }
    } while( 3 * inc[s] < n);

    clock_t start_time = clock();
    int j, d;
    for (d = inc[s]; d > 0; d = inc[s--]) {
        for (i = d; i < n; i++) {
            for (j = i; j >= d && mas[j - d] > mas[j]; j -= d) {
                int temp = mas[j];
                mas[j] = mas[j - d];
                mas[j - d] = temp;
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
    free(inc);
    return 0;
}


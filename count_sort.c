#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n;
    scanf("%d", &n);
    const int MAX_NUMBER = 100000;
    int* count = (int*)malloc(sizeof(int) * MAX_NUMBER);
    int* mas = (int*)malloc(sizeof(int) * n);
    if (count == 0 || mas == 0) {
        printf("Memory allocation error\n");
        return 0;
    }
    int i;
    for (i = 0; i < MAX_NUMBER; i++) {
        count[i] = 0;
    }
    clock_t start_time = clock();
    for (i = 0; i < n; i++) {
        mas[i] = rand() % MAX_NUMBER;
        count[mas[i]]++;
    }

    int j;
    for (i = 0; i < MAX_NUMBER; i++) {
        for (j = 0; j < count[i]; j++) {
            printf("%d ", i);
        }
    }
    clock_t finish_time = clock();
    printf("\n");
    printf("work time:%f\n", (double) (finish_time - start_time) / CLOCKS_PER_SEC);
    free(count);
    free(mas);
    return 0;
}



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n;
    scanf("%d", &n);
    const int MAX_NUMBER = 100000;
    int* count = (int*)malloc(sizeof(int) * MAX_NUMBER);
    int* mas = (int*)malloc(sizeof(int) * n);

    int i;
    for(i = 0; i < MAX_NUMBER; i++) {
        count[i] = 0;
    }

    for(i = 0; i < n; i++) {
        scanf("%d", &mas[i]);
        count[mas[i]]++;
    }

    int j;
    for(i = 0; i < MAX_NUMBER; i++) {
        for(j = 0; j < count[i]; j++) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("work time:%f\n", (double) clock() / CLOCKS_PER_SEC);
    return 0;
}



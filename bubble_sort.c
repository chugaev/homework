#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int n ;
    scanf("%d", &n);
    int* mas = (int*)malloc(sizeof(int) * n);

    int i;
    for(i = 0; i < n; i++) {
        scanf("%d", &mas[i]);
    }

    int j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(mas[j] > mas[j + 1]) {
                int temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    for(i = 0; i < n; i++) {
        printf("%d ", mas[i]);
    }

    printf("\n");

    printf("work time:%f\n", (double) clock() / CLOCKS_PER_SEC);
	free(mas);
    return 0;
}


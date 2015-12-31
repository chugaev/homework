#include <stdio.h>
#include <string.h>

void main() {
    FILE * f;
    f = fopen("input", "r");
    if (f == NULL) {
        perror ("Error opening file");
        return;
    }
    char str[256];
    while (fgets(str, 256, f)) {
        int i;
        for (i = 0; i < strlen(str); i++) {
            if ('/' == str[i] && i != 0 ) {
                if (str[i - 1] == '/') {
                    int j;
                    for (j = i + 1; j < strlen(str); j++) {
                        printf("%c", str[j]);
                    }
                    break;
                }
            }
        }
    }
}

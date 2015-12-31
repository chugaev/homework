#include <stdio.h>
#include <string.h>

void main() {
    char e;
    printf("Enter symbol: ");
    scanf("%c", &e);
    printf("Enter string: ");
    char str[256];
    scanf("%s", str);
    int i;
    for(i = 0; i < strlen(str); i++) {
        if (str[i] != e) {
            printf("%c", str[i]);
        }
    }
    printf("\n");
}

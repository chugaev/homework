#include <stdio.h>
#include <string.h>

void reverse_string(char * str, int len) {
    int i;
    for (i = 0; i < len / 2; i++) {
        char tmp = str[len - i - 1];
        str[len - i - 1] = str[i];
        str[i] = tmp;
    }
}

void main() {
	const int MAX_SIZE = 111;
    char num1[MAX_SIZE];
    char num2[MAX_SIZE];
    scanf("%s%s", num1, num2);
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int i;
    for (i = len1; i < len2; i++) {
        num1[i] = '0';
    }

    for (i = len2; i < len1; i++) {
        num2[i] = '0';
    }
    int len  = len1 > len2 ? len1 : len2;
    num1[len] = '\0';
    num2[len] = '\0';
    reverse_string(num1, len);
    reverse_string(num2, len);
    for (i = 0; i < len; i++) {
        if (num1[i] > num2[i]) {
            printf("num1 > num2\n");
            return;
        }
        if (num1[i] < num2[i]) {
            printf("num1 < num2\n");
            return;
        }
    }
    printf("num1 = num2\n");    
}

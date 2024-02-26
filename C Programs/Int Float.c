#include <stdio.h>
#include <string.h>

int main() {
    char number[50];
    printf("Enter a number: ");
    scanf("%s", number);

    if (strchr(number, '.') != NULL) {
        printf("The number is a float.\n");
    } else {
        printf("The number is an integer.\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    char str[100];
    int words = 0, newline = 1, characters = 0, spaces = 0;
    char ch;

    printf("Enter text and end with '~':\n");
    int i = 0;
    while ((ch = getchar()) != '~') {
        str[i] = ch;
        i++;
    }
    str[i] = '\0';

    i = 0;
    if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
        words++;
    }
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            spaces++;
            if (str[i+1] != ' ' && str[i+1] != '\n' && str[i+1] != '\0') {
                words++;
            }
        } else if (str[i] == '\n') {
            newline++;
            if (str[i+1] != ' ' && str[i+1] != '\n' && str[i+1] != '\0') {
                words++;
            }
        } else if (str[i] != ' ' && str[i] != '\n') {
            characters++;
        }
        i++;
    }

    printf("Total number of words : %d\n", words);
    printf("Total number of lines : %d\n", newline);
    printf("Total number of characters : %d\n", characters);
    printf("Total number of spaces : %d\n", spaces);

    return 0;
}

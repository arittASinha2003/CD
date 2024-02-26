#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if",
    "int", "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};

bool isKeyword(char *str) {
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true; // It's a keyword
        }
    }
    return false; // Not a keyword
}

bool isValidIdentifier(char *str) {
    // Check if it's a keyword
    if (isKeyword(str)) {
        return false;
    }

    // Check if the first character is a letter or underscore
    if (!(isalpha(str[0]) || str[0] == '_')) {
        return false;
    }

    // Check each character in the string
    for (int i = 1; i < strlen(str); i++) {
        // If the character is not a letter, digit, or underscore, it's invalid
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return false;
        }
    }

    // If all checks passed, it's a valid identifier
    return true;
}

int main() {
    char str[100];
    printf("Enter an identifier: ");
    scanf("%[^\n]s", str); // Read the entire line including spaces

    if (isValidIdentifier(str)) {
        printf("%s is a valid identifier.\n", str);
    } else {
        printf("%s is not a valid identifier.\n", str);
    }

    return 0;
}

// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// // List of C keywords to check against
// const char *keywords[] = {
//     "auto", "break", "case", "char", "const", "continue", "default", "do",
//     "double", "else", "enum", "extern", "float", "for", "goto", "if",
//     "int", "long", "register", "return", "short", "signed", "sizeof",
//     "static", "struct", "switch", "typedef", "union", "unsigned", "void",
//     "volatile", "while"
// };

// int isKeyword(char* str) {
//     int num_keywords = sizeof(keywords) / sizeof(char *);
//     for (int i = 0; i < num_keywords; i++) {
//         if (strcmp(str, keywords[i]) == 0)
//             return 1;
//     }
//     return 0;
// }

// int isValidIdentifier(char* str) {
//     if (!isalpha(str[0]) && str[0] != '_') // First character must be a letter or underscore
//         return 0;
//     for (int i = 1; str[i] != '\0'; i++) {
//         if (!isalnum(str[i]) && str[i] != '_') // Subsequent characters must be alphanumeric or underscore
//             return 0;
//     }
//     if (isKeyword(str)) // Identifier must not be a keyword
//         return 0;
//     return 1;
// }

// int main() {
//     char identifier[100];
//     printf("Enter an identifier: ");
//     fgets(identifier, 100, stdin); // Use fgets instead of scanf
//     // Remove newline character if present
//     if (identifier[strlen(identifier) - 1] == '\n')
//         identifier[strlen(identifier) - 1] = '\0';
//     if (isValidIdentifier(identifier))
//         printf("%s is a valid identifier.\n", identifier);
//     else
//         printf("%s is not a valid identifier.\n", identifier);
//     return 0;
// }

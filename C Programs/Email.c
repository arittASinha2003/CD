#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidEmail(char *email) {
    int atCount = 0;
    int dotCount = 0;
    int length = strlen(email);
    
    // Check for '@' and '.'
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            atCount++;
        } else if (email[i] == '.') {
            dotCount++;
        } else if ((email[i] >= 'a' && email[i] <= 'z') || (email[i] >= 'A' && email[i] <= 'Z') || (email[i] >= '0' && email[i] <= '9')) {
            continue;
        } else {
            return false; // Invalid character found
        }
    }
    
    // There should be only one '@' and at least one '.'
    if (atCount != 1 || dotCount < 1) {
        return false;
    }
    
    // Check if '@' is not the first or last character
    if (email[0] == '@' || email[length - 1] == '@') {
        return false;
    }
    
    // Check if '.' is not the first or last character
    if (email[0] == '.' || email[length - 1] == '.') {
        return false;
    }
    
    // Check if '@' is not followed by a '.'
    for (int i = 0; i < length - 1; i++) {
        if (email[i] == '@' && email[i + 1] == '.') {
            return false;
        }
    }
    
    // Check if consecutive '.' exists
    for (int i = 0; i < length - 1; i++) {
        if (email[i] == '.' && email[i + 1] == '.') {
            return false;
        }
    }
    
    return true;
}

int main() {
    char email[100];
    printf("Enter an email address: ");
    scanf("%s", email);
    
    if (isValidEmail(email)) {
        printf("Valid email address\n");
    } else {
        printf("Invalid email address\n");
    }
    
    return 0;
}

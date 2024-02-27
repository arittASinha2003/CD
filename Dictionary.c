#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

// Function to compare two strings
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Main function
int main() {
    char sentence[1000];
    char *words[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Tokenize the sentence into words
    char *token = strtok(sentence, " \t\n");
    while (token != NULL && wordCount < MAX_WORDS) {
        words[wordCount] = malloc(strlen(token) + 1);
        strcpy(words[wordCount], token);
        token = strtok(NULL, " \t\n");
        wordCount++;
    }

    // Sort the words in dictionary order
    qsort(words, wordCount, sizeof(char *), compareStrings);

    printf("\nSorted Words in Dictionary Order:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // Free the allocated memory
    }

    return 0;
}

#include <stdio.h>
#include <ctype.h>

// Function to count the number of words in a sentence
int countWords(char sentence[]) {
    int count = 0;
    int i = 0;
    while (sentence[i] != '\0') {
        if (sentence[i] == ' ') {
            count++; // Increment the word count when a space is encountered
        }
        i++;
    }
    count++; // Increment for the last word
    return count;
}

// Function to count the number of vowels in a sentence
int countVowels(char sentence[]) {
    int count = 0;
    int i = 0;
    while (sentence[i] != '\0') {
        char ch = tolower(sentence[i]); // Convert the character to lowercase
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++; // Increment the vowel count if a vowel is encountered
        }
        i++;
    }
    return count;
}

// Main function
int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin); // Read the sentence
    int wordCount = countWords(sentence); // Count the words
    int vowelCount = countVowels(sentence); // Count the vowels
    printf("Number of words: %d\n", wordCount); // Print the word count
    printf("Number of vowels: %d\n", vowelCount); // Print the vowel count
    return 0;
}

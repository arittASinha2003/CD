#include <stdio.h>

// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Numbers less than or equal to 1 are not prime
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // If the number is divisible by any number less than its square root, it's not prime
        }
    }
    return 1; // If no factors found, then it is prime
}

// Function to print the first n prime numbers
void printPrimes(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            printf("%d ", num); // Print the prime number
            count++; // Increment the count of prime numbers
        }
        num++; // Move to the next number
    }
}

// Main function
int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("First %d prime numbers are: ", n);
    printPrimes(n); // Call the function to print prime numbers
    return 0;
}

#include <stdio.h>

// Function to read the elements of the matrix
void readMatrix(int n, int matrix[][n]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to transpose the matrix
void transpose(int n, int matrix[][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}

// Function to print the matrix
void printMatrix(int n, int matrix[][n]) {
    printf("Transposed Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &n);
    int matrix[n][n];
    readMatrix(n, matrix); // Read the matrix
    transpose(n, matrix); // Transpose the matrix
    printMatrix(n, matrix); // Print the transposed matrix
    return 0;
}

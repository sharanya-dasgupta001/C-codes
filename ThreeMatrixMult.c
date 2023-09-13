/*
Let A,B and C be 3 matrices with integer entries. Write a program to compute ABC. If ABC is not defined,
your program should print an error message. The sizes of A,B and C will only be known at runtime. Your
program should dynamically allocate memory to store these matrices. You should also try to minimise the
number of arithmetic operations required to compute the product. You may assume that all entries of all the
matrices involved can be stored as int type variables.
Input format: The input, provided via the terminal, will consist of two positive integers mA and nA,
corresponding to the number of rows and columns of A, followed by the mA × nA entries of A. Next, the
dimensions and entries of B and C, respectively, will be provided using the same format as for A.
Output format: If the matrix product ABC is not defined, your program should print ERROR on the screen
and exit. If the matrix product ABC is defined, your program should print the entries of ABC in matrix form;
i.e., entries of the first row should be printed separated by spaces on the first line; thereafter, the entries of
the second row should be printed on the second line, and so on. You need not worry about vertically aligning
the matrix entries.
Sample input 1
4 2
13 99
64 43
95 65
2 86
2 10
31 3 67 50 78 20 63 27 9 83
12 28 12 1 97 98 57 47 9 54
10 3
87 29 31
49 86 60
70 16 23
15 2 37
46 75 74
56 80 72
12 54 50
93 73 65
41 26 14
78 17 79
Sample output 1
2563169 2765235 2966020
2461379 2181226 2649776
3680395 3267905 3964780
2011906 2246030 2359720
*/
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a matrix
struct Matrix {
    int rows;
    int cols;
    int **data;
};

// Function to dynamically allocate memory for a matrix
struct Matrix* createMatrix(int rows, int cols) {
    struct Matrix* matrix = (struct Matrix*)malloc(sizeof(struct Matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix->data[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to read a matrix from the file
void readMatrix(FILE *file, struct Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->cols; j++) {
            fscanf(file, "%d", &matrix->data[i][j]);
        }
    }
}

// Function to compute the matrix product of A, B, and C
struct Matrix* matrixProduct(struct Matrix *A, struct Matrix *B, struct Matrix *C) {
    struct Matrix* result = createMatrix(A->rows, C->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < C->cols; j++) {
            int sum = 0;
            for (int k = 0; k < A->cols; k++) {
                sum += A->data[i][k] * B->data[k][j];
            }
            result->data[i][j] = sum;
        }
    }
    return result;
}

// Function to free the memory allocated for a matrix
void freeMatrix(struct Matrix *matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        free(matrix->data[i]);
    }
    free(matrix->data);
    free(matrix);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s input_file\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    int mA, nA, mB, nB, mC, nC;
    fscanf(file, "%d %d", &mA, &nA);
    struct Matrix *A = createMatrix(mA, nA);
    readMatrix(file, A);

    fscanf(file, "%d %d", &mB, &nB);
    struct Matrix *B = createMatrix(mB, nB);
    readMatrix(file, B);

    fscanf(file, "%d %d", &mC, &nC);
    struct Matrix *C = createMatrix(mC, nC);
    readMatrix(file, C);

    fclose(file);

    if (nA != mB || nB != mC) {
        printf("ERROR: Matrix product ABC is not defined.\n");
        freeMatrix(A);
        freeMatrix(B);
        freeMatrix(C);
        return 1;
    }

    struct Matrix *ABC = matrixProduct(A, B, C);

    // Print the resulting matrix ABC
    for (int i = 0; i < ABC->rows; i++) {
        for (int j = 0; j < ABC->cols; j++) {
            printf("%d ", ABC->data[i][j]);
        }
        printf("\n");
    }

    // Free memory and cleanup
    freeMatrix(A);
    freeMatrix(B);
    freeMatrix(C);
    freeMatrix(ABC);

    return 0;
}

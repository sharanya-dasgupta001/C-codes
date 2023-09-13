/*
Write a C program that takes a 9x9 matrix as input and checks if it is a valid sudoku solution.
Sample Input 1:
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 3 4 5 6 7 8 9 1
5 6 7 8 9 1 2 3 4
8 9 1 2 3 4 5 6 7
3 4 5 6 7 8 9 1 2
6 7 8 9 1 2 3 4 5
9 1 2 3 4 5 6 7 8
Sample Output 1:
Valid.
Sample Input 2:
2 1 3 4 5 6 7 8 9
3 6 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 3 4 5 6 7 8 9 1
5 6 7 8 9 1 2 3 4
8 9 1 2 3 4 5 6 7
3 4 5 6 7 8 9 1 2
6 7 8 9 1 2 3 4 5
9 1 2 3 4 5 6 7 8
Sample Output 2:
Invalid.
*/
#include <stdio.h>
#include <stdlib.h>
#define N 9

int isinRange (int sudoku[][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudoku[i][j] <= 0 || sudoku[i][j] > 9) {
                return 0;
            }
        }
    }
    return 1;
}

int isValidSudoku(int sudoku[][N])
{
    if (isinRange(sudoku) == 0) {
        return 0;
    }

    int unique[N + 1];

    for (int i = 0; i < N; i++) {

        for (int Z = 0; Z <= N ; Z++) {
            unique[Z] = 0;
        }

        for (int j = 0; j < N; j++) {

            int Z = sudoku[i][j];

            if (unique[Z]) {
                return 0;
            }
            unique[Z] = 1;
        }
    }

    for (int i = 0; i < N; i++) {

        for (int Z = 0; Z <= N ; Z++) {
            unique[Z] = 0;
        }

        for (int j = 0; j < N; j++) {

            int Z = sudoku[j][i];

            if (unique[Z]) {
                return 0;
            }
            unique[Z] = 1;
        }
    }

    for (int i = 0; i < N - 2; i += 3) {

        for (int j = 0; j < N - 2; j += 3) {

            for (int Z = 0; Z <= N ; Z++) {
                unique[Z] = 0;
            }

            for (int k = 0; k < 3; k++) {

                for (int l = 0; l < 3; l++) {

                    int X = i + k;
                    int Y = j + l;
                    int Z = sudoku[X][Y];

                    if (unique[Z]) {
                        return 0;
                    }
                    unique[Z] = 1;
                }
            }
        }
    }

    return 1;
}

int main(int argc, char *argv[])
{
    int sudoku[N][N];

    FILE *fp;

    if (NULL == (fp = fopen (argv[1], "r"))) {
        printf ("Error opening file\n");
        exit (1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            fscanf (fp, "%d", &sudoku[i][j]); 
        }
    }

    /*for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf ("%d ", sudoku[i][j]); 
        }
        printf ("\n");
    }*/

    if (isValidSudoku(sudoku)) {
        printf ("Valid.\n");
    }
    else {
        printf ("Invalid.\n");
    }

    fclose (fp);
}

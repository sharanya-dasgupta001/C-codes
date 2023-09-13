/*
Given a sequence a0, a1, a2, . . ., an−1 of n distinct integers, and a target integer target, write a C program to
print all those pairs ai, aj (i < j) in the given sequence, such that ai + aj = target. Your program should
print “No such pair” if there is no such pair that sums up to target. The input will consist of the value of n,
target and the set of n numbers, as given below. For example, for Sample Input 1, the value of n is 7, value of
target is 13, and the 7 numbers a0, a1, a2, . . ., a6 follow after that.
Sample Input 1:
7 13 1 2 3 4 5 10 11
Sample Output 1:
2 11
3 10
Sample input 2:
9 11 -7 0 1 5 6 11 18 25 40
Sample output 2:
-7 18
0 11
5 6
Sample input 3:
9 9 -7 0 1 5 6 11 18 25 40
Sample output 2:
No such pair
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main (int argc, char *argv[]) {

    int n, k, *arr, arrayIndex;

    FILE *fp;

    if (NULL == (fp = fopen (argv[1], "r"))) {
        printf ("Error opening file\n");
        exit (1);
    }

    /* Read the values of n and k */
    fscanf (fp, "%d", &n);
    fscanf (fp, "%d", &k);

    /* Create an array of size n and read in the elements */
    arr = (int *)(malloc (n * sizeof(int)));

    for (arrayIndex = 0; arrayIndex < n; arrayIndex++) {
        fscanf (fp, "%d", &arr[arrayIndex]);
    }

    /* Print the array elements */
    /*for (arrayIndex = 0; arrayIndex < n; arrayIndex++)
        printf ("%d ", arr[arrayIndex]);
    printf ("\n");*/

    /* WRITE YOUR CODE STARTING FROM HERE. 
       YOU MAY WRITE SEPARATE FUNCTIONS AS WELL */

    int i, j, pairExists = 0;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                printf ("%d %d\n", arr[i], arr[j]);
                pairExists = 1;
            }
        }
    }

    if (pairExists == 0) {
        printf ("No such pair exists\n");
    }
    
    

    free (arr);
    fclose (fp);
    return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define n 100

double A[n][n];
double B[n][n];
double C[n][n];

float tdiff (struct timeval *start, struct timeval *end) {
    return (end->tv_sec - start->tv_sec) + 1e-6 * (end->tv_usec - start->tv_usec);
}

int main (int argc, const char *argv[]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
           A[i][j] = (double)rand() / (double)RAND_MAX;
           B[i][j] = (double)rand() / (double)RAND_MAX;
           C[i][j] = 0;
        }
    }
                      
    struct timeval start, end;
    gettimeofday (&start, NULL);

    for (int k = 0; k < n; ++k) {                // Row Major Traversal Faster due to memory arrangement
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < n; ++i) {
                C[i][j] += A[i][k] * B[k][j];   // A Column Major, B Row Major
            }
        }
    }

    gettimeofday (&end, NULL);
	printf ("%0.6f\n", tdiff (&start, &end));

	return 0;
}

/*
o/p-
running time 0.002996 s
*/

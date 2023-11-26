/* CLAB / 2023 / LT1 */

#define USAGE "Usage: max-multiple-of-3 (i|o) [<length>]\n" \
    "i -> create sample input\n" \
    "o -> create sample output\n"

#define MY_MAX 1000
#define BLUE 0
#define RED 1

#include "common.h"
#include <time.h>

int main(int ac, char *av[])
{
    char c;
    int n, count[2] = {0, 0}, xflag, yflag, i;
    float x, y, N, max_x[2], min_x[2], max_y[2], min_y[2];

    if (ac < 2 || (av[1][0] != 'i' && av[1][0] != 'o'))
        ERR_MESG(USAGE);

    if (av[1][0] == 'i') {
        if (ac < 3 || 0 >= (n = atoi(av[2])))
            ERR_MESG("To create sample input: need positive length for test sequence\n");
        srand((int) time(NULL));
        printf("%d\n", n);
        for (i = 0; i < n; i++) {
            N = rand();
            printf("%.4f ", (int) N % MY_MAX + N / (double) RAND_MAX);
            N = rand();
            printf("%.4f ", (int) N % MY_MAX + N / (double) RAND_MAX);
            if (rand() % 2) puts("B");
            else puts("R");
        }
    }
    else if (av[1][0] == 'o') {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%f %f %c", &x, &y, &c);
            if (c == 'R') c = RED;
            else if (c == 'B') c = BLUE;
            else {
                fprintf(stderr, "Skipping unexpected character %c\n", c);
                continue;
            }
            count[c] += 1;
            if (count[c] == 1) {
                max_x[c] = min_x[c] = x;
                max_y[c] = min_y[c] = y;
            }
            else {
                if (x > max_x[c]) max_x[c] = x;
                else if (x < min_x[c]) min_x[c] = x;
                if (y > max_y[c]) max_y[c] = y;
                else if (y < min_y[c]) min_y[c] = y;
            }
        }

        xflag = yflag = 0;
        for (i = 0; i < 2; i++) {
            if (max_x[i] < min_x[1-i])
                yflag = 1;
            if (max_y[i] < min_y[1-i])
                xflag = 1;
        }
        if (xflag) putchar('X');
        if (yflag) putchar('Y');
        if (xflag + yflag == 0)
            puts("Not possible");
        else puts("");
    }

    return 0;
}

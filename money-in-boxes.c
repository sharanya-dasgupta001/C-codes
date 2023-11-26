/* Solution to 22-back/Q2 */
/* This uses the input format that was initially specified
 * (X occurs at the end instead of at the beginning).
 * The core idea is the same in both cases.
 */
#include "common.h"

int main(int ac, char *av[])
{
    int m, *n, X;
    int num_boxes = 0, total_boxes = 0;

    if (1 != scanf("%d", &m))
        ERR_MESG("Invalid input");
    /* Allocate space to store capacities */
    if (NULL == (n = Malloc(m, int)))
        ERR_MESG("money-in-boxes: out of memory\n");
    for (int i = 0; i < m; i++)
        if (1 != scanf("%d", n+i))
            ERR_MESG("Invalid input");
    if (1 != scanf("%d", &X))
        ERR_MESG("Invalid input");
    /* To get X, we need p1 = ceil(X/n[0]) smallest boxes (that have coins);
     * to get p1 smallest boxes, we need ceil(p1/n[1]) boxes of size s2;
     * and so on.
     */
    for (int i = 0; i < m; i++) {
        num_boxes = ceil(X / ((double) n[i]));
        total_boxes += num_boxes;
        X = num_boxes;
    }

    printf("%d\n", total_boxes);
    free(n);
    return 0;
}

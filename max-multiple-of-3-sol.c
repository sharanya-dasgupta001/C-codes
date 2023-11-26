/* CLAB / 2023 / LT1 */

#define USAGE "Usage: max-multiple-of-3 (i|o) [<length>]\n" \
    "i -> create sample input\n" \
    "o -> create sample output\n"

#include "common.h"
#include <time.h>

int main(int ac, char *av[])
{
    int c, counts[10] = {0}, remainder, num_to_remove, n, i, j;

    if (ac < 2 || (av[1][0] != 'i' && av[1][0] != 'o'))
        ERR_MESG(USAGE);

    if (av[1][0] == 'i') {
        if (ac < 3 || 0 >= (n = atoi(av[2])))
            ERR_MESG("To create sample input: need positive length for test sequence\n");
        srand((int) time(NULL));
        for (i = 0; i < n; i++)
            putchar('0' + rand() % 10);
        putchar('\n');
    }
    else if (av[1][0] == 'o') {
        while ('\n' != (c = getchar())) {
            if (isdigit(c))
                counts[c - '0'] += 1;
            else
                fprintf(stderr, "Skipping unexpected character %c\n", c);
        }
        for (i = 0; i < 10; i++)
            remainder += counts[i] * (i % 3);
        remainder %= 3;
        switch (remainder) {
        case 0: break;
        case 1:
            for (i = 1; i < 10; i += 3)
                if (counts[i] > 0) {
                    counts[i] -= 1;
                    break;
                }
            if (i >= 10) {
                num_to_remove = 2;
                for (i = 2; i < 10 && num_to_remove > 0; i += 3) {
                    if (counts[i] >= num_to_remove) {
                        counts[i] -= num_to_remove;
                        num_to_remove = 0;
                    }
                    else {
                        num_to_remove -= counts[i];
                        counts[i] = 0;
                    }
                }
                assert(num_to_remove == 0);
            }
            break;
        case 2:
            for (i = 2; i < 10; i += 3)
                if (counts[i] > 0) {
                    counts[i] -= 1;
                    break;
                }
            if (i >= 10) {
                num_to_remove = 2;
                for (i = 1; i < 10 && num_to_remove > 0; i += 3) {
                    if (counts[i] >= num_to_remove) {
                        counts[i] -= num_to_remove;
                        num_to_remove = 0;
                    }
                    else {
                        num_to_remove -= counts[i];
                        counts[i] = 0;
                    }
                }
                assert(num_to_remove == 0);
            }
            break;
        }
        for (i = 9; i >= 0; i--)
            for (j = 0; j < counts[i]; j++)
                putchar('0' + i);
        putchar('\n');
    }

    return 0;
}

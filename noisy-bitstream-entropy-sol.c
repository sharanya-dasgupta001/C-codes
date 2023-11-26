/* CLAB / 2023 / LT1 */

#define USAGE "Usage: noisy-bitstream-entropy (i|o) [<length> <probability of 1> <probability of noisy bits>]\n" \
    "i -> create sample input\n" \
    "o -> create sample output\n"

#define MY_RAND_MAX 10000

#include "common.h"
#include <math.h>
#include <time.h>

static void create_sample_input(int, double, double);
static double entropy(int, int);
static void find_min_max_entropy();

int main(int ac, char *av[])
{
    if (ac < 2 || (av[1][0] != 'i' && av[1][0] != 'o'))
        ERR_MESG(USAGE);

    if (av[1][0] == 'i') {
        if (ac < 5)
            ERR_MESG("To create sample input: need length, probability of 1 and noisy bits\n");
        int n = atoi(av[2]);
        double prob_one = atof(av[3]);
        double prob_noise = atof(av[4]);

        if (n <= 0 || prob_one < 0 || prob_one > 1 ||
            prob_noise < 0 || prob_noise > 1 ||
            (prob_one + prob_noise > 1))
            ERR_MESG("Illegal value for length / probability");
        create_sample_input(n, prob_one, prob_noise);
    }
    else if (av[1][0] == 'o') {
        find_min_max_entropy();
    }

    return 0;
}

static void create_sample_input(int n, double prob_one, double prob_noise)
{
    int i;
    int thresh_one = MY_RAND_MAX * prob_one,
        thresh_noise = thresh_one + MY_RAND_MAX * prob_noise;

    srand((int) time(NULL));
    for (i = 0; i < n; i++) {
        int r = rand() % MY_RAND_MAX;
        if (r < thresh_one) putchar('1');
        else if (r < thresh_noise) putchar('?');
        else putchar('0');
    }
    putchar('\n');
    return;
}

static double entropy(int min, int max)
{
    double total, prob_smaller, prob_larger;

    if (min == 0) return 0;
    
    total = min + max;
    prob_smaller = min / total;
    prob_larger = max / total;
    return -(prob_smaller * log2(prob_smaller) + prob_larger * log2(prob_larger));
}

static void find_min_max_entropy(void)
{
    int c, count0 = 0, count1 = 0, count_noisy = 0, max, min;
    double min_entropy, max_entropy;

    while ('\n' != (c = getchar())) {
        switch (c) {
        case '0':
            count0++; break;
        case '1':
            count1++; break;
        case '?':
            count_noisy++; break;
        default:
            fprintf(stderr, "Skipping unexpected character %c\n", c);
            break;
        }
    }

    if (count0 > count1) {
        max = count0; min = count1;
    }
    else {
        max = count1; min = count0;
    }

    if (count_noisy == 0) { /* no variations possible */
        min_entropy = max_entropy = entropy(min, max);
    }
    else {
        min_entropy = entropy(min, max + count_noisy);
        if (count_noisy < max - min)
            max_entropy = entropy(min + count_noisy, max);
        else
            max_entropy = 1;
    }
        
    printf("%.3f %.3f\n", min_entropy, max_entropy);
    return;
}

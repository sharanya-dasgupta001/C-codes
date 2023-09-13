/*
Recall how a group of children (say c1, c2, . . . , cp) playing hide-and-seek choose the thief. They stand in a
circle, and one particular child ck (called the counter, say) recites some kind of a rhyme consisting of m ≥ 1
words, starting with himself / herself and moving on to the next child (ck+1, ck+2, . . . in order) after reciting
each word. Because the children are standing in a circle, the counter moves to c1 after reaching cp. The child
at whom the rhyme ends is eliminated from subsequent rounds of counting. Counting for the next round starts
from the child following the eliminated child (in the circular order described above). The process continues
until one child remains.
Write a program to simulate the above activity, and to determine the order in which children are eliminated.
Input format: An integer (say n) specifying the number of test cases, followed by n lines, each of which
corresponds to a test case. These lines will each consist of 3 integers, corresponding to the total number
of children (p), the serial number of the child chosen as the counter (k), and the length of the rhyme (m),
respectively. Note that numbering of children starts from 1.
Output format: Your program should print the serial numbers of the children in the order in which they are
eliminated, and finish with the number of the child who becomes the thief. For each test case, your program
should print the output in a single line.
Sample input 1:
3
4 1 10
5 2 6
5 2 3
Sample output 1:
2 3 1 4
2 4 3 1 5
4 2 1 3 5
Sample input 2:
4
14 1 10
15 2 4
15 3 2
20 1 1
Sample output 2:
10 6 3 1 14 2 5 9 4 13 8 11 7 12
5 9 13 2 7 12 3 10 1 11 6 4 8 15 14
4 6 8 10 12 14 1 3 7 11 15 5 13 9 2
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/

#include <stdio.h>

void hide_and_seek(int p, int k, int m) {
    int children[1000]; // Assuming the maximum number of children is 1000
    int eliminated_children[1000];
    int current_index = k - 1;
    int i, j;

    // Initialize the array representing children
    for (i = 0; i < p; i++) {
        children[i] = i + 1;
    }

    for (i = 0; i < p - 1; i++) {
        // Find the index of the child to be eliminated after counting m words
        int next_index = (current_index + m - 1) % p;

        // Add the eliminated child to the list
        eliminated_children[i] = children[next_index];

        // Shift the children array to remove the eliminated child
        for (j = next_index; j < p - 1; j++) {
            children[j] = children[j + 1];
        }

        // Update the current index for the next round of counting
        current_index = next_index % (p - 1);

        p--; // Decrement the number of remaining children
    }

    // The last remaining child is the thief
    int thief = children[0];

    // Output the order in which children are eliminated and the thief
    for (i = 0; i < p - 1; i++) {
        printf("%d ", eliminated_children[i]);
    }
    printf("%d\n", thief);
}

int main() {
    int n, i;
    int p, k, m;

    scanf("%d", &n); // Number of test cases

    for (i = 0; i < n; i++) {
        scanf("%d %d %d", &p, &k, &m);
        hide_and_seek(p, k, m);
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LENGTH 80

void readLines(char lines[MAX_LINES][MAX_LENGTH], int *lineCount) {
    printf("Enter multiple lines of text (Press Ctrl+D or Ctrl+Z to finish):\n");

    *lineCount = 0;
    while (*lineCount < MAX_LINES && fgets(lines[*lineCount], MAX_LENGTH, stdin)) {
        (*lineCount)++;
    }
}

void printLines(char lines[MAX_LINES][MAX_LENGTH], int lineCount, int choiceOddEven, int choiceReverse) {
    printf("Result:\n");

    int start = (choiceOddEven == 1) ? 0 : 1;
    int step = 2;
    int end = lineCount;

    if (choiceReverse == 2) {
        start = (lineCount % 2 == 0) ? (lineCount - 1) : (lineCount - 2);
        step = -2;
        end = (choiceOddEven == 1) ? 0 : 1;
    }

    for (int i = start; i >= end; i += step) {
        printf("Line %d: %s", i + 1, lines[i]);
    }
}

int main() {
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;

    readLines(lines, &lineCount);

    if (lineCount == 0) {
        printf("No lines of text entered.\n");
        return 1;
    }

    int choiceOddEven, choiceReverse;
    printf("Options:\n");
    printf("1. Print odd-numbered lines\n");
    printf("2. Print even-numbered lines\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choiceOddEven);

    printf("\nOptions:\n");
    printf("1. Print lines in their original order\n");
    printf("2. Print lines in reverse order\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choiceReverse);

    printLines(lines, lineCount, choiceOddEven, choiceReverse);

    return 0;
}

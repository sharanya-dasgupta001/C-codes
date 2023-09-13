/*
Write a C program to compute the product of two positive integers. The input integers may contain
up to 100 digits (0–9). Thus, you will not be able to use the usual builtin types (int, long int, etc.)
to store the inputs. You may not use the GNU Multiple Precision (MP) Arithmetic Library, or any
other similar library or C++ class.
Input format: You will be given the 2 positive integers as strings via standard input (i.e., the
terminal). Each integer will consist of a sequence of up to 100 digits. The strings will be separated by
one newline character.
Output format: Your program should print the product of the two numbers. For full credit, the
result should not contain any leading zeros.
Sample input 1
92233720368547758078771
922337203685477580798221876
Sample output 1
85070591730234615864546096442815997303410743394396
Sample input 2
1000000000000000000000000000000000000000050
1000000000000000000000000000000000000000050
Sample output 2
1000000000000000000000000000000000000000100000000000000000000000000000000000000002500
*/
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 200  // Maximum length of input and result arrays

void multiply(char result[], const char num1[], const char num2[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int product[MAX_DIGITS] = {0};  // Store the partial products
    int resultLen = len1 + len2 - 1;

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            product[i + j] += (num1[len1 - i - 1] - '0') * (num2[len2 - j - 1] - '0');
        }
    }

    int carry = 0;
    for (int i = 0; i < resultLen; i++) {
        product[i] += carry;
        carry = product[i] / 10;
        product[i] %= 10;
    }

    // Handle the last carry if needed
    while (carry) {
        product[resultLen++] = carry % 10;
        carry /= 10;
    }

    // Convert the result array to a string
    int resultIdx = 0;
    for (int i = resultLen - 1; i >= 0; i--) {
        result[resultIdx++] = product[i] + '0';
    }
    result[resultIdx] = '\0';
}

int main() {
    char num1[MAX_DIGITS];
    char num2[MAX_DIGITS];
    char result[MAX_DIGITS * 2];  // The result can be at most twice the length of inputs

    // Read input numbers as strings
    scanf("%s\n%s", num1, num2);

    multiply(result, num1, num2);

    printf("%s\n", result);

    return 0;
}

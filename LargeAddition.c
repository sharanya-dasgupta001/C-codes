/*
Write a C program that can add one positive integer to another positive integer, and subtract one positive
integer from another positive integer. The input integers may contain up to 100 digits (0–9). Thus, you will
not be able to use the usual builtin types (int, long int, etc.) to store the inputs. You may not use the
GNU Multiple Precision (MP) Arithmetic Library, or any other similar library or C++ class.
Input format: You will be given 3 strings via standard input (i.e., the terminal). The first two will be the
two integers; each integer will consist of a sequence of up to 100 digits. The two integers may not necessarily
contain the same number of digits. The third string will consist of a single character, either + or -.
Output format: If the third string is +, your program should print the sum of the two numbers; if it is -,
your program should print the result obtained by subtracting the second number from the first (in this case,
the second number will be no greater than the first number). Note that the sum of two 100-digit numbers
may contain more than 100 digits.
Sample input 1
100. . .005 (50 digits in all)
100. . .005 (50 digits in all)
+
Sample output 1
200. . .010 (50 digits in all)
Sample input 2
100. . .010 (100 digits in all)
10. . .005 (99 digits in all)
-
Sample output 2
90. . .005 (99 digits in all)
*/
#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 100

// Function to reverse a string
void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to add two large positive integers represented as strings
void add(char num1[], char num2[], char result[]) {
    int carry = 0;
    int i = 0;

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    while (i < len1 || i < len2) {
        int digit1 = (i < len1) ? (num1[i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[i] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;

        i++;
    }

    if (carry > 0) {
        result[i] = carry + '0';
        i++;
    }

    result[i] = '\0';
    reverse(result, i);
}

// Function to subtract two large positive integers represented as strings
void subtract(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    int carry = 0;
    int i = 0;

    while (i < len1 || i < len2) {
        int digit1 = (i < len1) ? (num1[i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[i] - '0') : 0;

        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result[i] = diff + '0';
        i++;
    }

    // Remove leading zeros
    while (i > 1 && result[i - 1] == '0')
        i--;

    result[i] = '\0';
    reverse(result, i);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    char num1[MAX_DIGITS + 1];
    char num2[MAX_DIGITS + 1];
    char op;
    char result[MAX_DIGITS + 2]; // Extra 1 for potential carry and 1 for null terminator

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening input file: %s\n", argv[1]);
        return 1;
    }

    fgets(num1, sizeof(num1), file);
    fgets(num2, sizeof(num2), file);
    fscanf(file, " %c", &op); // Read the operator (space before %c to ignore leading newline)
    fclose(file);

    // Remove trailing newline characters from num1 and num2
    num1[strcspn(num1, "\n")] = '\0';
    num2[strcspn(num2, "\n")] = '\0';

    if (op == '+') {
        add(num1, num2, result);
        printf("Sum: %s\n", result);
    } else if (op == '-') {
        subtract(num1, num2, result);
        printf("Difference: %s\n", result);
    } else {
        printf("Invalid operator. Please use '+' or '-'.\n");
        return 1;
    }

    return 0;
}

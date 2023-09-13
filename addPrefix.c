/*
Suppose you are given with a File consisting of English alphabets only. You are asked to add a particular prefix
to all the occurrences of a specific string (case-sensitive) in the said file. Write a program that can serve the
purpose.
Input Format
Input will be provided in a File. The name of the File is to be taken as a command-line argument. The File will
contain characters from the English alphabet.
Output Format
Output will be generated in the same input File.
Command-line Arguments
./prog <input_filename> <string> <prefix>
Sample Input 1
Input from command-line:
./prog input.txt set data
Content of input.txt before execution of the program:
This was a set of items.
Sample Output 1
Contents of input.txt after execution of the program:
This was a dataset of items.
Sample Input 2
Input from command-line:
./prog input.txt SO SO
Content of input.txt before execution of the program:
There was an SOS message
Sample Output 2
There was an SOSOS message
Sample Input 3
Input from command-line:
./prog input.txt hi bye
Content of input.txt before execution of the program:
Say Hi to me!!!
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void add_prefix_to_string(char *content, const char *search_string, const char *prefix) {
    char *occurrence = content;
    int search_len = strlen(search_string);
    int prefix_len = strlen(prefix);

    while ((occurrence = strstr(occurrence, search_string))) {
        memmove(occurrence + prefix_len, occurrence, strlen(occurrence) + 1);
        memcpy(occurrence, prefix, prefix_len);
        occurrence += prefix_len + search_len;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_filename> <string> <prefix>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *search_string = argv[2];
    const char *prefix = argv[3];

    FILE *file = fopen(input_file, "r");
    if (!file) {
        printf("Error opening input file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *)malloc(file_size + 1);
    if (!content) {
        printf("Memory allocation error.\n");
        fclose(file);
        return 1;
    }

    fread(content, 1, file_size, file);
    fclose(file);

    add_prefix_to_string(content, search_string, prefix);

    file = fopen(input_file, "w");
    if (!file) {
        printf("Error opening output file.\n");
        free(content);
        return 1;
    }

    fwrite(content, 1, strlen(content), file);
    fclose(file);
    free(content);

    return 0;
}

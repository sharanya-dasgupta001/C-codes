/*
Write a C program that takes as input a text file containing a single line of text and reverses the order of words
in it. Assume that the line contains no more than 128 characters, and is terminated by a newline character.
The delimiter between two words is the space character.
Sample Input 1:
We, the people of India.
Sample Output 1:
India. of people the We,
Sample input 2:
Always do right. This will gratify some people and astonish the rest.
Sample output 2:
rest. the astonish and people some gratify will This right. do Always
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 128
 
void reverse(char* begin, char* end)
{
    char temp;
    while (begin < end) {
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
 
void reverseText(char* s)
{
    char* word_begin = s;
    char* temp = s;
 
    while (*temp) {
        temp++;
        if (*temp == '\0') {
            reverse(word_begin, temp - 1);
        }
        else if (*temp == ' ') {
            reverse(word_begin, temp - 1);
            word_begin = temp + 1;
        }
    }
 
    reverse(s, temp - 1);
}
 
int main(int argc, char *argv[])
{
    FILE *fp;

    if (NULL == (fp = fopen (argv[1], "r"))) {
        printf ("Error opening file\n");
        exit (1);
    }

    char s[MAX];
    fscanf(fp, "%[^\n]s", s);

    char* temp = s;
 
    reverseText(s);

    printf("%s", s);
    printf ("\n");

    fclose (fp);
    return 0;
}

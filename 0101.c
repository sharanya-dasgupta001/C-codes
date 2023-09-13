/*
Write a C program that takes in an array of 0s and 1s, and rearranges the array so that all 0s are at
the beginning and all 1s are at the end.
Input format: You will be given a sequence of 0s and 1s. The number of 0s and 1s will not be
known to you in advance (but it will be small enough to be stored in a variable of int type).
Output format: Your program should print the rearranged array.
Sample input 1
0101010101
Sample output 1
0000011111
Sample input 2
00000
Sample output 2
00000
Sample input 3
11111
Sample output 3
11111
*/
#include<stdio.h>
#include<string.h>
int main(){
    char str[100],out[100]="";
    scanf("%s",&str);
    int i=0,zeroes=0,ones=0;
    while (str[i]!='\0')
    {
        if(str[i]=='0')
            zeroes++;
        else if(str[i]=='1')
            ones++;
        i++;
    }
    for (int i = 0; i < zeroes; i++)
    {
        strcat(out,"0");
    }
    for (int i = 0; i < ones; i++)
    {
        strcat(out,"1");
    }
    printf("%s",out);
    
}
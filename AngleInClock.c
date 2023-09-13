/*
Recall that any arbitrary pair of hands (denoting hour, minute, and second) of a clock forms two possible
angles within themselves. Write a program that takes an angle (any one of the possible two) between the other
pair of hands (minute and hour) and returns whether there is any valid time satisfying the given angle or not,
assuming that the second hand of a clock is residing at 12. Consider that an angle between a pair of hands of
a clock will always remain within [0; 2pi].
[20 marks]
Input Format
The input (to be read from stdin) is to be taken as a pair of integers (say m and n) representing the fractional
angle between the minute and hour hands (in radian), i.e. the angle is m pi / n
n radian.
Output Format
The output (to be printed to stdout) will show whether the angle is VALID or INVALID.
Sample Input 0
1 1
Sample Output 0
VALID
Sample Input 1
5 2
Sample Output 1
INVALID
Sample Input 2
7 11
Sample Output 2
INVALID
*/
#include <stdio.h>

int main() {
    int m,n;
    printf("Enter m");
    scanf("%d",&m);
    printf("Enter n");
    scanf("%d",&n);
    if(((m*180/n)<=360) && ((m*30%n)==0))
        printf("VALID");
    else
        printf("INVALID");

    return 0;
}
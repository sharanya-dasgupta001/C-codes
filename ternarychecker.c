/*
Write a program that can take a C statement, which uses ternary operator, as user input and return
whether the input statement is valid or not. Consider that validity of a statement only depends on the
structure of the ternary operator used in the statement.
Input Format
The input (to be read from stdin) is the C statement.
Output Format
The output (to be printed to stdout) will be VALID or INVALID depending upon whether the C statement
is valid or not, respectively.

Sample Input 0:
c = (a < b) ? a : b;
Sample Output 0:
VALID
Sample Input 1:
a = 2 > 3 ? 2 : 3 > 4 ? 3 : 4;
Sample Output 1:
VALID
Sample Input 2:
val = a ? b: c ? d ? : ;
Sample Output 2:
INVALID
*/
#include<stdio.h>
#include<string.h>
int main(){
    char str[100];
    fgets(str,100,stdin);
    int i=0,flag,count_qn=0,count_colon=0;
    while (str[i]!='\0')
    {
        if (str[i]=='?'){
            flag=0; count_qn++;}
        else if (str[i]==':'){
            flag=1; count_colon++;}
        i++;
    }
    if ((str[strlen(str)-2]!=';') || (count_colon!=count_qn))
        flag=0;
    if(flag==0)
        printf("INVALID");
    else if(flag==1)
        printf("VALID");
}
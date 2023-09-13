/*
For a sequence of n (> 1) natural numbers S =< a1; a2; : : : ; an >, dene
p(S) = sum of all terms.
and
q(S) = sum of difference of consecutive terms.
We say S is an A-sequence if the following holds:
(a) a1 >= a2 >= a3 >= ... ... ... >= an
(b) p(S) and q(S) are relatively prime.
Given a sequence S of natural numbers as user input, write a program to verify whether the given sequence is
an A-sequence or not.
Input Format
The input (to be read from stdin) will start with the number of elements in the sequence followed by the
sequence. The sequence may be read as an array of integers.
Output Format
The output (to be printed to stdout) will show whether the input sequence is A-sequence or not.
Sample Input 0
3 7 5 3
Sample Output 0
A-sequence
Sample Input 1
5 50 40 30 20 10
Sample Output 1
NOT A-sequence
Sample Input 2
4 1 2 3 4
Sample Output 2
NOT A-sequence
*/

#include<stdio.h>
int gcd(int a,int b){
    if (a>b){
        b=a+b;
        a=b-a;
        b=b-a;
    }
    for (int i = 2; i <= a; i++)
    {
        if((a%i==0)&&(b%i==0)){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n, Ps=0, Qs=0,this_term,prev_term,flag=1;
    scanf("%d",&n);
    scanf("%d",&prev_term);
    Ps=this_term;
    for (int i = 0; i < n-1; i++)
    {
        scanf("%d",&this_term);
        if(this_term>prev_term){
            printf("NOT A-sequence");
            flag=0;
            break;
        }
        Ps+=this_term;
        Qs+=(prev_term-this_term);
        
    }
    if(flag){
        if(gcd(Ps,Qs)){
            printf("NOT A-sequence");
        }
        else
           printf("A-sequence");
}
    
}
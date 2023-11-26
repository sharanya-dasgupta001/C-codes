/*
Consider 2 sequences of letters (a–z), A and B, stored in arrays. 
(a) Write a program to find the number of (possibly overlapping) occurrences of the sequence B in A.
(b) Write a program to find whether the multisets corresponding to A and B are equal.
*/
#include<stdio.h>
#include<string.h>


int main(){
char A[100],B[100];
scanf("%s",A);
scanf("%s",B);
int i=0,j=0,count=0;
while ((A[i]!='\0') && (B[i]!='\0') )
{
    if(A[i]==B[i]){
        count++;
    }
    i++;j++;
}
printf("\n %d",count);
for (int i = 0; i < strlen(A); i++)
    {
        for (int j = i+1; j < strlen(A); j++)
        {
            if(A[j]<A[i]){
                char temp= A[j];
                A[j] = A[i];
                A[i] = temp;
            }
        }
        
    }
for (int i = 0; i < strlen(B); i++)
    {
        for (int j = i+1; j < strlen(B); j++)
        {
            if(B[j]<B[i]){
                char temp= B[j];
                B[j] = B[i];
                B[i] = temp;
            }
        }
        
    }
int multiset=0;
i=0;j=0;
// puts(A);
// puts(B);
while ((A[i]!='\0') || (B[i]!='\0') )
{
    if(A[i]!=B[i]){
        multiset=1;
    }
    i++;j++;
}
if(multiset==1){
    printf("\nNot Same Multiset");
}
else{
    printf("\n Same Multiset");
}
return 0;
}

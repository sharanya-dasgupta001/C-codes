#include<stdio.h>
int main(){
    int a;
    printf("Enter a Number");
    scanf("%d",&a); 
    if ((a%2)==0)
        printf("The Number is even");
    else
    printf("The number is odd");
    return 0;
}
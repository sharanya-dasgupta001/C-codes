#include<stdio.h>
void printDigit(int n){
    if((n>=0)&&(n<=9)){
        printf("printDigit %d\n",n);
        printf("%d\n",n);
    }
    return;
}
void printNumber(int n){
    if(n>=10){
        printf("printnum %d\n",n);
        printNumber(n/10);
    }
    printDigit(n%10);
    return;
}
void printNumberReverse(int n){
    if(n>0){
        printf("printNumReverse %d\n",n);
        printDigit(n%10);
        printNumberReverse(n/10);
        return;
    }
    
}
int main(){
    int n;
    scanf("%d",&n);
    printNumber(n);
    printNumberReverse(n);
}
#include<stdio.h>

int main(){
    int age1 = 22;
    int age2 = 25;
    int *ptr1=&age1;
    int *ptr2=&age2;
    printf("%u %u \ndifference=%u",ptr1,ptr2,ptr1-ptr2);
    *ptr2=age1;
    printf("\ncomparison=%u",ptr2==ptr1);
  
    return 0;
}
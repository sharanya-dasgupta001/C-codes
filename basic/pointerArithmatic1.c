#include<stdio.h>

int main(){
    int age=22;
    int *ptr1=&age;
    printf("ptr=%u\n",ptr1);
    ptr1++;                     // 4 byte shift
    printf("ptr=%u\n",ptr1);
    ptr1--;
    printf("ptr=%u\n\n",ptr1);

    float aprice=25;
    float *ptr2=&aprice;
    printf("ptr=%u\n",ptr2);
    ptr2++;                     // 4 byte shift
    printf("ptr=%u\n",ptr2);
    ptr2--;
    printf("ptr=%u\n\n",ptr2);
    
    char a='A';
    char *ptr3=&a;
    printf("ptr=%u\n",ptr3);
    ptr3++;                     // 1 byte shift
    printf("ptr=%u\n",ptr3);
    ptr3--;
    printf("ptr=%u\n",ptr3);
    return 0;

    return 0;


}
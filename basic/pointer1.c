#include<stdio.h>

int main(){

    int age=22;
    int *ptr=&age;

    printf("%p ", &age);
    printf("%p ", ptr);
    printf("%p\n",&ptr);

    printf("%u ", &age);
    printf("%u ", ptr);
    printf("%u\n",&ptr);

    printf("%d ", age);
    printf("%d ", *ptr);
    printf("%d\n",*(&age));

    int **pptr=&ptr;
    printf("%u ",(*pptr));
     printf("%u",*(*pptr));

    return 0;
}
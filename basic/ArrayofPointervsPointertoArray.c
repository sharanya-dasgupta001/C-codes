#include<stdio.h>
int main(){
    int* X[10];                     // Array of of 10 pointers to integer
    int (*Y)[10];                   // Pointer to array of 10 intergers
    printf("%ld ",sizeof(X));       // Array of 10 pointers each 8 bytes
    printf("%ld ",sizeof(X[0]));    // Address 8 bytes
    printf("%ld ",sizeof(Y));       // Y is address 8 bytes
    printf("%ld ",sizeof(Y[0]));    // Y[0] is an array of 10 integers each 4 byte, We should not try to access Y[1],Y[2],...
}
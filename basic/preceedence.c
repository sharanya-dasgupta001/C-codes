//006preceedence.c
#include<stdio.h>
int main(){
    int a = 5*2-2*3 ;
    printf("%d\n",a); 
    a = 5*2/2*3;
    printf("%d\n",a); 
    a = 5*(2/2)*3 ;
    printf("%d\n",a); 
    a = 5+2/2*3;
    printf("%d\n",a); 
    return 0;
}
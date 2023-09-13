#include<stdio.h>
int main(){
    int x=2;
    if(x=1){    // x=1 returns non zero value which taken as TRUE by c compiler
        printf("x is equal to 1");
    }
    else{ 
        printf("x is not equal to 1");

    }
     printf("\n");
    if(x=0){    // x=0 returns zero value which taken as FALSE by c compiler
        printf("x is equal to 1");
    }
    else{ 
        printf("x is not equal to 1");

    }
}
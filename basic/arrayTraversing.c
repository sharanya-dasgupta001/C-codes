#include<stdio.h>

int main(){
    int number[5];
    int *ptr = &number[0];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d ",(ptr+i));
    }
    printf("\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",*(ptr+i));
    }
    

    return 0;
}
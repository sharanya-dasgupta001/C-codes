#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr;
    
    ptr = (int*)calloc(5,sizeof(int));
    
    for (int i = 1; i <= 5; i++)
    {
     ptr[i-1]=(2*i);
    }
    for (int i = 0; i < 5; i++)
    {
     printf("%d ",ptr[i]);
    }

    ptr=realloc(ptr,6*sizeof(float));
    printf("\n");

    for (int i = 1; i <= 5; i++)
    {
     ptr[i-1]=(2*i)-1;
    }
    for (int i = 0; i < 5; i++)
    {
     printf("%d ",ptr[i]);
    }

    free(ptr);


    return 0;
}
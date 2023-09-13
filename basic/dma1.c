#include<stdio.h>
#include<stdlib.h>

int main(){
    float *ptr;
    
    ptr = (float*)malloc(100*sizeof(float));
    int n;
    scanf("%d",&n);
    ptr=realloc(ptr,n*sizeof(float));

    for (int i = 0; i < n; i++)
    {
     scanf("%f",&ptr[i]);
    }
    for (int i = 0; i < n; i++)
    {
     printf("%f ",ptr[i]);
    }
    free(ptr);


    return 0;
}
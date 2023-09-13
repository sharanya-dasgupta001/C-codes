#include<stdio.h>
#include<stdlib.h>

int main(){
    float *ptr;
    int n;
    scanf("%d",&n);
    ptr = (float*)calloc(n,sizeof(float));

    // for (int i = 0; i < 5; i++)
    // {
    //  scanf("%f",&ptr[i]);
    // }
    for (int i = 0; i < n; i++)
    {
     printf("%f ",ptr[i]);
    }
    
    free(ptr);

    return 0;
}
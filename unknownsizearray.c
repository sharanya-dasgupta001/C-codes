#include<stdio.h>
#include<stdlib.h>

int main(){
    int* array,size=5;  
    array = (int*)calloc(size,sizeof(int));
    if(NULL==array){
        perror("out of memory\n");
        exit(1);
    }
    
    int i=0;
    scanf("%d",&array[i]);
    i++;
    char ch;
    while ('\n'!=(ch=getchar()))
    {
        if (i>size-1)
        {
            size*=2;
            array = (int*)realloc(array,size*sizeof(int));
            if(NULL==array){
                perror("out of memory\n");
                exit(1);
            }
        }
        
        scanf("%d",&array[i]);
        i++;

    }
    for (int j = 0; j < i; j++)
    {
        printf("%d ",array[j]);
    }
    
    return 0;

}
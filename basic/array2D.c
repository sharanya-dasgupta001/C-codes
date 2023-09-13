#include<stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    int data[n][3]; //[Row][Column]
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d",&data[i][0],&data[i][1],&data[i][2]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("p=%d k=%d m=%d\n",data[i][0],data[i][1],data[i][2]);
    }

    return 0;
}
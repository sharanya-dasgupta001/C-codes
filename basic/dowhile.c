// take input till user enter a odd number
#include<stdio.h>
int main(){
    int n;
    do
    {
        scanf("%d",&n);
        printf("%d",n);
        if (n%2==0)
        {
            break;
        }
        
    } while (1);
    return 0;
    
}
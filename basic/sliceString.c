#include<stdio.h>
#include<string.h>

void slice(char str[],int m,int n){
    int i=0;
    for ( i = m; i <= n; i++)
    {
        printf("%c",str[i]);
   }
    
}

int main(){

    int m,n;
    char str[100];
    fgets(str,100,stdin);
    scanf("%d %d",&m,&n);
    slice(str,m,n);

    return 0;
}
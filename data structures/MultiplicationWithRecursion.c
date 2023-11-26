#include<stdio.h>
#include<math.h>

int mult(int x,int y){
    if (y==0)
    {
        return 0;
    }
    if (y%2==0)
    {
        return (2*mult(x,y/2));
    }
    else
    {
        y=floor(y/2);
        return (2*mult(x,y)+x);
    }
    
}

int main(){
    int x,y;
    scanf("%d%d",&x,&y);
    printf("%d",mult(x,y));
    return 0;
}
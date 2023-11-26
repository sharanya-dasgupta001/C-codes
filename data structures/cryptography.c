#include<stdio.h>
#include<math.h>
int modExp(int x,int y,int N){
    if (y==0)
    {
        return 1;
    }
    int z = modExp(x,floor(y/2),N);
    if (y%2==0)
    {
        return ((z*z)%N);
    }
    else
        return((x*z*z)%N);
}
int main(){
    int x,y,N;
    scanf("%d%d%d",&x,&y,&N);
    printf("%d",modExp(x,y,N));
    return 0;
}
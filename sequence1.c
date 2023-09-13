/*Read a sequence of positive integers a0, a1, a2, . . . (the length of the
sequence will not be known a priori) and determine 
     4
maxi Σ ai+j .
    j=0
Note that you do not need to store the complete sequence in order to
compute the required quantity.*/
#include<stdio.h>
void main(){
    int a,b=0,max=0,n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a);
        if ((b+a)>max)
            max = b+a;
        b=a;
    }
    printf("\n%d",max);
    
}
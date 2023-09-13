/*
You are given two arrays, A and B, each containing the same set S of n distinct integers. For a given
x ∈ S, let indexA(x) and indexB(x) denote the position at which x occurs in A and B, respectively.
Write a program to find the element y of S for which
displacement(y) ≜ |indexA(y) − indexB(y)|
is maximum. If there are multiple ys all of which have the same maximum displacement value, your
program should select the smallest y.

Input format: Your program should read n from stdin, followed by the elements of A and the
elements of B in order.
Output format: Your program should print 3 space-separated integers: y, indexA(y) and indexB(y),
where y is as defined above. The 3 integers should be printed on a single line.

Sample input:
4
0 1 2 3 ←− indices (not part of the input)
1 2 3 4 ←− elements of A
4 3 2 1 ←− elements of B
Sample output:
1 0 3
Explanation: The displacement for both 1 and 4 is 3, while the displacement for 2 and 3 is 1.
Thus, the maximum displacement is observed for elements 1 and 4. Of these, 1 is the smaller value
(y); it occurs at index 0 and 3 in arrays A and B, respectively.
note: For now, it is enough to solve this using any simple method that you can think of. Later,
we will consider the question of how to solve the problem efficiently
*/
#include<stdio.h>
int absdiff(int a, int b){
    int diff=a-b;
    if(diff<0)
        return ((-1)*diff);
    return diff;
}
int main(int ac, char *av[]){

    int n;
    int diff=0,maxdiff=0,ia=0,num=0,ib=0;
    scanf("%d",&n);
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(a[i]==b[j]){
                diff=absdiff(i,j);
                //printf("%d %d %d\n",a[i],b[j],diff);
                if(diff>maxdiff){
                    num=a[i];
                    ia=i;
                    ib=j;
                    maxdiff=diff;
                    //printf("%d %d %d %d %d\n",num,ia,ib,maxdiff,diff);
                }
                if((diff==maxdiff)&&(a[i]<num)){
                    num=a[i];
                    ia=i;
                    ib=j;
                    maxdiff=diff;
                    //printf("%d %d %d %d %d\n",num,ia,ib,maxdiff,diff);
                }
            }
        }
    }
    printf("%d %d %d",num,ia,ib);
    
}
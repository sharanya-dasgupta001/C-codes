/*
Your input is a positive integer n, followed by an n × n square matrix A with each cell filled with a
digit between 0 and 9. Write a program to display A in the terminal rotated clockwise at an angle
of 45◦ as shown in the example below.
5
1 2 3 4 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
5 4 3 2 1
−→
    1
   0 2
  0 0 3
 0 0 0 4
5 0 0 0 5
 4 0 0 0
  3 0 0
   2 0
    1

*/
#include<stdio.h>
int main(){
    char c = getchar();
    int n = c-'0';
    int arr[n][n];
    int a=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
    {
        scanf("%d",&arr[i][j]);
    }
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n-i; j++)
        {
            printf(" ");
        }
        int n1=i,n2=0;
        while (n2<=i)
        {
            printf("%d ",arr[n1][n2]);
            n1--;
            n2++;
        }
        printf("\n");

        
        
    }
    for (int i = n; i > 1; i--)
    {
        for (int j = 0; j < n-i+1; j++)
        {
            printf(" ");
        }
        int n1=n-1,n2=n-i+1;
        while (n2<=n-1)
        {
            printf("%d ",arr[n1][n2]);
            n1--;
            n2++;
        }
        printf("\n");

        
        
    }
    
    
}
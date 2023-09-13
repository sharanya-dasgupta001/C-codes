/*
Suppose a file contains a sequence of k integers read in a row major fashion from an n×m matrix A.
The dimensions n and m of the matrix are unknown. Write a program to print the possible values
of the matrix A that can lead to the contents given in the file.

Input format: the number k itself, followed by the k matrix elements.
Output format: All the distinct matrices for which the given input sequence may be obtained.

Successive matrices should be separated by a blank line. Matrices should be printed in increasing
order of the number of rows.
Sample input 0: 4 1 3 5 6
Sample output 0:
1 3 5 6
1 3
5 6
1
3
5
6
Sample input 1: 6 2 5 3 7 2 5
Sample output 1:
2 5 3 7 2 5
2 5 3
7 2 5
2 5
3 7
2 5
2
5
3
7
2
5
*/
#include<stdio.h>
void printMatrix(int arr[],int row,int col,int n){
    int i=0;
    
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                printf("%d ",arr[i]);
                i++;
            }
            printf("\n");
        }
        

    
}
int main(){
   
    int n ,flag=0;
    
    //printf("%d\n",n);
    scanf("%d",&n);
    int arr[n];
    int c,i=0;
    while ('\n' != (c = getchar())) {
        
        
        scanf("%d",&arr[i]);
        i++;
    }

    
    
    for (int row = 1; row <=n ; row++)
    {
        if(n%row==0){
            int col=n/row;
            //printf("%d %d %d",row,col,n);
            printMatrix(arr,row,col,n);
            printf("\n");
        }
    }
    
    return 0;

}
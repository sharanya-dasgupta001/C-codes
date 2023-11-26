/* MTech(CS) I year 2022-2023 Lab Test 3 (November 25, 2022) Q3
Write a program to merge k sorted lists of integers into one sorted list. 
Note that the k lists may not
contain an equal number of elements.
Let n denote the total number of integers contained in the k lists together. 
Your program should work
for any number of lists (k) and elements (n) (as long as k and n can be stored 
in an int type variable).
Storage for each individual list should be allocated dynamically.
For full credit, your merging algorithm should run in O(n log k) time.
Input format: The input data will be provided in a text file. The first line of 
the file will contain the
value of k. Each of the remaining k lines in the file will contain the size of a 
list and the elements of the
list, as shown below.
4
3 24 99 103 ←− The first list contains 3 elements: 24, 99 and 103.
4 -1 1 1 1001
2 -10 -1
Your program should take a single command-line argument corresponding to the name 
of the input data
file.
Output format: Your program should print the integers in the merged list on a single 
line, separated
from each other by spaces. For the input given above, your program should produce the 
output below.
-10 -1 -1 1 1 24 99 103 1001
*/
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int* Merge(int* arr1,int n1,int* arr2,int n2){
    arr1[n1]=INT_MAX;
    arr2[n2]=INT_MAX;
    int* merged;
    merged = (int*)malloc((n1+n2+1)*sizeof(int));
    int i=0,j=0,k=0;
    for (int k = 0; k < n1+n2; k++)
    {
        if (arr1[i]<=arr2[j])
        {
            merged[k]=arr1[i];
            i++;
            continue;
        }
        if (arr2[j]<arr1[i])
        {
            merged[k]=arr2[j];
            j++;
            continue;
        }
    }
    
    return merged;
}
int main(){
    int k,n;
    scanf("%d",&k);
    int *arr1;
    int *arr2;
    int n1,n2;
    scanf("%d",&n1);
    arr1 = (int*)malloc(n1*sizeof(int));
    for (int j = 0; j < n1; j++)
    {
        scanf("%d",&arr1[j]);
    }
    for (int i = 0; i < k-1; i++)
    {
        scanf("%d",&n2);
        arr2 = (int*)malloc(n2*sizeof(int));
        for (int j = 0; j < n2; j++)
        {
            scanf("%d",&arr2[j]);
        }
        arr1 = realloc(arr1,(n1+n2+1)*sizeof(int));
        arr1 = Merge(arr1,n1,arr2,n2);
    
        n1 = n1+n2;
          
    }
    for (int i = 0; i < n1; i++)
    {
        printf("%d ",arr1[i]);
        arr1;
    }
    
    
}
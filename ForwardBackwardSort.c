/*
Forward Backward Sort is a sorting algorithm that can be used to arrange the elements of an array in
increasing order. The essential idea here is that in each iteration, we traverse the array twice: first
from left to right, and then from right to left. For your convenience, we provide the algorithm below.
Each iteration of the algorithm is broken up into 2 stages:
• The first stage loops through the array from left to right. During the loop, adjacent items are
compared; if the value on the left is greater than the value on the right, then the values are
swapped. At the end of the first stage, the largest number will reside at the end of the array.
• The second stage loops through the array in the opposite direction, starting from the last but
one item, and moving back to the start of the array. Here also, adjacent items are compared
and are swapped if required, so that at the end of the second stage, the smallest number will be
moved to the first position of the array.
The second iteration is similar to the first, except that the two elements at the ends of the array (the
minimum and the maximum) are no longer considered. Thus, the second iteration works with n − 2
elements (where n is the number of elements in the input). Similarly, the third iteration works with
n − 4 elements.
If, during a pass over the array, no swap occurs, the algorithm stops. At this point, all elements in
the array are arranged in increasing order.
Example: Let us consider an example array (5 1 4 2 8 0 2)
First Forward Pass:
(5 1 4 2 8 0 2) =⇒ (1 5 4 2 8 0 2), Swap since 5 > 1
(1 5 4 2 8 0 2) =⇒ (1 4 5 2 8 0 2), Swap since 5 > 4
(1 4 5 2 8 0 2) =⇒ (1 4 2 5 8 0 2), Swap since 5 > 2
(1 4 2 5 8 0 2) =⇒ (1 4 2 5 8 0 2), No swap since 5 ≤ 8
(1 4 2 5 8 0 2) =⇒ (1 4 2 5 0 8 2), Swap since 8 > 0
(1 4 2 5 0 8 2) =⇒ (1 4 2 5 0 2 8), Swap since 8 > 2
After the first forward pass, the greatest element (8) moves to the last position in the array. Next, the
first backward pass starts.
First Backward Pass:
(1 4 2 5 0 2 8) =⇒ (1 4 2 5 0 2 8), No swap since 0 ≤ 2
(1 4 2 5 0 2 8) =⇒ (1 4 2 0 5 2 8), Swap since 5 > 0
(1 4 2 0 5 2 8) =⇒ (1 4 0 2 5 2 8), Swap since 2 > 0
(1 4 0 2 5 2 8) =⇒ (1 0 4 2 5 2 8), Swap since 4 > 0
(1 0 4 2 5 2 8) =⇒ (0 1 4 2 5 2 8), Swap since 1 > 0
After the first backward pass, the smallest element (0) moves to the first position of the array.
Second Forward Pass:
(0 1 4 2 5 2 8) =⇒ (0 1 4 2 5 2 8), No swap since 1 ≤ 4
(0 1 4 2 5 2 8) =⇒ (0 1 2 4 5 2 8), Swap since 4 > 2
(0 1 2 4 5 2 8) =⇒ (0 1 2 4 5 2 8), No swap since 4 ≤ 5
(0 1 2 4 5 2 8) =⇒ (0 1 2 4 2 5 8), Swap since 5 > 2
Second Backward Pass:
(0 1 2 4 2 5 8) =⇒ (0 1 2 2 4 5 8), Swap since 4 > 2
Now, the array is already sorted, but our algorithm doesn’t know this. The algorithm completes a
third forward pass, during which no swap occurs. It then stops.
(0 1 2 2 4 5 8) =⇒ (0 1 2 2 4 5 8)
Input format: You will be given n ≤ 100 integers as inputs. The integers will be separated by
spaces. The number n itself will not be provided as input.
Output format: Your program should print the n input integers in ascending order in one single
line. The integers should be separated by one blank space. You will not get credit if your program
implements a sorting algorithm different from the one described above.
Sample input 1
0 -9 -10 204 81 999 -9883 81 1000
Sample output 1
-9883 -10 -9 0 81 81 204 999 1000
*/
#include<stdio.h>
int main(){
    int arr[100],n=0,num;
    char a ='A';
    
    while (a != '\n')
    {
        scanf("%d",&num);
        arr[n]=num;
        n++;
        a=getchar();
    }
    //printf("%d",n);
    int end=n-1,start=0;
    for (int i = 0; i < n/2; i++)
    {
        // Forward pass
        int flag=0;
        for(int j = start; j <= end; j++)
        {
            if(j==start)
                continue;
            else if(arr[j-1]>arr[j]){
                int temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
                flag=1;
            }
        }
        // Check if swap happened or not
        if(flag==0)
            break;
        // backward pass
        flag=0;
        end--;
        for(int j = end; j >= start; j--)
        {
            if(j==end)
                continue;
            else if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag=1;
            }
        }
        // Check if swap happened or not
        if(flag==0)
            break;
        start++;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    
    
   return 0;
}
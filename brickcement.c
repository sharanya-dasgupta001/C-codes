/*
Suppose a number of cubical bricks of equal sizes are set up in succession in a row. In some of the
positions in the said row, there can be multiple bricks perfectly aligned over each other (as shown in the
figure). There are additional bricks of the same shape to continue the construction. However, due to
shortage of bricks for further construction, you have been asked to fill some space with quick-setting
cement (to be poured onto that row) so that no cement spills over. Your only goal is to save maximum
number of cubical bricks by pouring quick-setting cement. The rest of the things will be managed by
the construction team. Write a program that takes the number of bricks already set up on the row and
return the number of maximum bricks you can save by pouring quick-setting cement.
Figure 1: The black cubes are bricks and the gray regions are covered by quick-setting cement.

Input Format
The input (to be read from stdin) comprises a series of non-negative integers representing the number of
bricks aligned over each other as they successively appear in the row.
Output Format
The output (to be printed to stdout) shows the maximum number of bricks that can be saved by pouring
quick-setting cement.
Sample Input 0:
0 1 0 2 1 0 1 3 2 1 2 1
Sample Output 0:
6
Sample Input 1:
4 2 0 3 2 5
Sample Output 1:
9
Sample Input 2:
9 0 9 0 9 0 9
Sample Output 2:
27
*/
#include <stdio.h>

int main() {
    int bricks[100];  // Assuming a maximum of 100 bricks in the input
    int n = 0;  // Number of bricks read
    char a;
    // Read the input
    while (a != '\n')
    {
        scanf("%d",&bricks[n]);
        n++;
        a=getchar();
    }
    

    int maxSavedBricks = 0;
    int maxHeight = 0,NewmaxHeight=0;
    int flag,counter;

    // Iterate through each position in the row
    for (int i = 0; i < n; i++) {
        flag=0;
        if (bricks[i] >= maxHeight) {
            maxHeight = bricks[i];
            flag=1;
            counter=i;
        } else {
            maxSavedBricks += maxHeight - bricks[i];
        }
    }
    // Corner Case 
    if (flag==0){
        for (int i = n-1; i > counter; i--)
        {   
            if (bricks[i] >= NewmaxHeight) {
                NewmaxHeight = bricks[i];
                maxSavedBricks=maxSavedBricks-(maxHeight-bricks[i]);
            } 
            else if(bricks[i]<NewmaxHeight){
                maxSavedBricks=maxSavedBricks-(maxHeight-bricks[i])+(NewmaxHeight-bricks[i]);
            }
        }
        

    }


    printf("%d\n", maxSavedBricks);

    return 0;
}

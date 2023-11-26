/*An eccentric person keeps all his money in one-rupee coins only. The
coins are put into small boxes of size s1, with each box containing
exactly n1 coins. These small boxes are put into larger boxes of size
s2. Each box of size s2 contains exactly n2 boxes of size s1. These
boxes are packed into even larger boxes of size s3, and so on
Write a program to determine the smallest number of boxes that have
to be opened in all in order to pay a given sum of money (Rs. X, say).
Input format. The input will be provided via standard input (stdin)
and be of the form
X m n1 n2 . . . nm
where the first integer X denotes a sum of money that has to be paid,
m denotes the number of distinct sizes of boxes used to store money;
n1 is the number of one-rupee coins stored in the smallest boxes; ni
(for i > 1) specifies the number of boxes of size si−1 that are stored in
each box of size si (si−1 < si).
Note that you do not need the actual values of s1, s2, . . . , sm to solve this problem.
Output format. Your program should print the minimum number of
boxes that have to be opened (a single integer) to pay Rs. X. 
You may assume that the person has enough money to pay the requested amount.

Sample input 1.
5 1 1 1 1 1 2

Sample output 1.
10

Explanation. Each box contains only one inner box, so five boxes
have to be opened in sequence to get Re. 1. Note that we are not told
the actual number of boxes of the largest size that the person has; we
assume that there are enough boxes to pay the required amount.

Sample input 2.
3 3 3 3 14

Sample output 2.
8

Explanation. There are 3 box sizes: small (s1), medium (s2) and
large (s3). Each box contains 3 smaller boxes/coins. One large box
has to be opened. This contains three medium sized boxes, two of
which will have to be opened. This will give us a total of 6 small boxes,
each containing 3 one-rupee coins. Five of these smallest boxes will
have to be opened, giving us Rs. 15, out of which only Rs. 14 needs
to be paid.*/

#include<stdio.h>
int main(){
    int m,X,n,NoOfBOx=0;
    scanf("%d %d",&X,&m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d",&n);
        if(X%n!=0){
            NoOfBOx+=(X/n)+1;
            X=(X/n)+1;}
        else{
            NoOfBOx+=(X/n);
            X=(X/n);}
        }
    printf("%d",NoOfBOx);
    

}
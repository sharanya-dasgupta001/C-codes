/*
The quality of research publications of a scientist is often characterized by his citation metrics. Every research
publication has a citation count that represents the number of times it has been referred in other research
publications, thereby indicating its credit. The h-index is one of the popular citation metrics that is defined
as the maximum value of h such that the given scientists has published h papers that have each been cited at
least h number of times. Suppose you are given the citation counts of the research publications of a scientist
in chronological order (i.e., following the order in which they were published). Write a program to compute
the h-index of the scientist.
Input Format
Input will be provided as two lines: the first line will contain a single integer n ≥ 1 specifying the number of
publications of the scientist; the second line will contain a list of n positive numbers (separated by spaces),
that represent the citation counts of the scientist’s research publications in chronological order.
Output Format
Your program should print a single integer, the h-index, to standard output.
Sample Input 1:
7
10 2 1 5 11 4 3
Sample Output 1:
4
Sample Input 2:
17
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
Sample Output 2:
1
Sample Input 3:
2
200 310
Sample Output 3:
2
Sample input 4:
20
12 3 49 11 26 2 31 1 6 88 9 57 26 5 51 0 3 33 1 21
Sample output 4:
11
Sample input 5:
7
10 2 1 5 11 4 3
Sample output 5:
4
Sample input 6:
55
4 10 10 21 21 12 5 13 0 0 0 1 1 0 2 29 0 3 9 27 1 0 1 48 1 0 0 0 8 169 33 40 47 30 14 7 0 0 66 33 70 1 0 185 0 4
38 1 55 6 10 88 105 4 0
Sample output 6:
18
*/
#include<stdio.h>
int max(int a, int b){
    if (a>=b)
    {
        return a;
    }
    else
        return b;
    
}
int main(){

    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    int h_index=1;
    int maxelement=0;
    for (int i = 0; i < n; i++)
    {   
        maxelement=max(maxelement,arr[i]);
    }

    for (int i = 1; i <= maxelement; i++)
    {   
        int count=0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j]>=i)
            {
                count++;
            }
        }
        if (count==i)
        {
            h_index=max(h_index,i);
        }
        
    }
    printf("%d",h_index);
    
    

    return 0;
}
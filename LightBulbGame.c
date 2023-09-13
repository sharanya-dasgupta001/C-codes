/*
Light Bulb Game. We have a set of n (n ≥ 1) light bulbs in a room, each labeled with a unique number
between 1 and n. All light bulbs are initially in the OFF state. A group of n (n ≥ 1) children, c1, c2, . . . , cn
enter the room one by one, in order. Child ck (1 ≤ k ≤ n) toggles the state of each light bulb (ON to OFF
/ OFF to ON, depending on the current state of the bulb), whose number is a multiple of k. Note that the
child does not touch any other light bulb. Thus, the child c1 enters the room first, and changes all light bulbs
to the ON state. The next child, c2, enters the room and turns OFF bulb numbers 2, 4, 6, 8 . . .. Similarly,
child c3 changes the state of bulb numbers 3, 6, 9 . . .; bulbs 3, 9, . . . are turned OFF, while bulbs 6, 12, . . .
are turned back ON. The game ends when cn leaves the room.
Write a program to read as input a number n from the terminal, and print which out of the n bulbs remain
ON after the game ends.
Sample input 1:
10
Sample output 1:
A list of numbers, each in a separate line, corresponding to the bulbs which remain ON after the 10th child
departs.
Sample input 2:
100
Sample output 2:
A list of numbers, each in a separate line, corresponding to the bulb numbers which remain ON after the
100th child departs.
*/

#include <stdio.h>

int main() {
    // Write C code here
    int bulb,i=0,j=0;
    printf("Enter the number of bulbs");
    scanf("%d",&bulb);
    for(i=1;i<=bulb;i++){
        int flag=0;
        for(j=1;j<=i;j++){
            if(i%j==0)
                flag+=1;
        }
        if((flag%2)!=0)
            printf("%d\n",i);
    }

    return 0;
}
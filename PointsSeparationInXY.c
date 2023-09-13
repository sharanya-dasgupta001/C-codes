/* 
You are given the coordinates of N ≤ 1000 points in the X-Y plane. Some of the points are coloured
red, while the remaining points are coloured blue as shown in the figures below. Write a program to
determine whether the red and blue points can be separated by a horizontal and/or vertical line.

Input format: The first line of the input will consist of the single integer N ≤ 1000. This will be
followed by N lines, each of which will contain 3 space-separated fields: 2 floating point numbers
corresponding to the X and Y coordinates of the point, and a single letter, R or B, denoting the
colour of the point.

Output format: Your program should print X and/or Y, if the points can be separated by a line
parallel to the X and/or Y axis. If the points cannot be separated in this way, your program should
print Not possible.
Sample input 1:
3
576.7917 600.9445 R
792.9193 496.3221 R
408.2261 808.3936 B
Sample output 1: XY
Sample input 2:
4
312.6470 472.3536 B
824.7356 480.2515 R
616.5823 648.6834 R
512.1858 112.3059 R
Sample output 2: Y
Sample input 3:
7
632.1380 336.4848 B
960.3505 384.4847 B
800.9382 536.1495 R
864.9716 712.3475 R
232.1350 592.0440 R
352.1127 304.5831 R
80.4339 464.8508 B
Sample output 3: Not possible
*/

#include "common.h"

#define BLUE 0
#define RED 1

int max(float arr[],int n){
	float max=-999999999999999;
	for ( int i=0; i<n ; i++){
	if(arr[i]>=max){
	max=arr[i];}
	}
	return max;
}
int min(float arr[],int n){
	float min=99999999999999;
	for ( int i=0; i<n ; i++){
	if(arr[i]<=min){
	min=arr[i];}
	}
	return min;
}
int main(int ac, char *av[])
{
    char c;
    float x, y;
    int r=0,b=0,n;

    scanf("%d", &n);
    
    float bluex[n],bluey[n],redx[n],redy[n];
    
    for (int i = 0; i < n; i++) {
      scanf("%f %f %c", &x, &y, &c);
      	if(c=='R'){
      		redx[r]=x;
      			
      		redy[r]=y;
      		r++;
      	}
      	if(c=='B'){
      		bluex[b]=x;
      		bluey[b]=y;
      		b++;
      	}
    }
    /*for(int i=0 ; i<r;i++){
    printf("%f %f",redx[i],redy[i]);}
    for(int i=0 ; i<b;i++){
    printf("%f %f",bluex[i],bluey[i]);}*/

    float maxbluex = max(bluex,b);
    //printf("%f",maxbluex);
    float maxbluey = max(bluey,b);
    //printf("%f",maxbluey);
    float maxredx = max(redx,r);
    //printf("%f",maxredx);
    float maxredy = max(redy,r);
    //printf("%f",maxredy);
    
    float minbluex = min(bluex,b);
    //printf("%f",minbluex);
    float minbluey = min(bluey,b);
    //printf("%f",minbluey);
    float minredx = min(redx,r);
    //printf("%f",minredx);
    float minredy = min(redy,r);
    //printf("%f",minredy);
    
    if((minbluey>maxredy)||(minredy>maxbluey)){
    printf("X");
    }
    if((minbluex>maxredx)||(minredx>maxbluex)){
    printf("Y");
    }
    if((minbluey<=maxredy)&&(minredy<=maxbluey)&&(minbluex<=maxredx)&&(minredx<=maxbluex))
    	printf("Not possible");
    

    return 0;
}

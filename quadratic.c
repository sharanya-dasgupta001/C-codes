/*Write a program to determine the roots of a quadratic equation
ax2 + bx + c = 0. Your program should ask for the values of a, b and
c, and print the roots (real or complex).*/
#include<stdio.h>
#include<math.h>
void main(){
    int a,b,c;
    float D,x1,x2;
    printf("Enter a,b,c");
    scanf("%d %d %d",&a,&b,&c);
    D = (b*b) - (4*a*c);
    if(D>=0){
        x1 = (-b + sqrt(D))/(2*a);
        x2 = (-b - sqrt(D))/(2*a);
        printf("Roots are %.3f and %.3f",x1,x2);
    }
    else{
        D=-D;
        x1=(-b/(2*a));
        x2=(sqrt(D)/(2*a));
        printf("Roots are %.2f+i%.2f and %.2f-i%.2f",x1,x2,x1,x2);
    }
}
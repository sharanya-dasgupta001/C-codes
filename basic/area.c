#include<stdio.h>
int main(){
    float side, radius, pi=3.14;
    printf("Enter Side:");
    scanf("%f",&side);
    printf("Enter Radius:");
    scanf("%f",&radius);
    printf("Area of Square is %f and Circle is %f",side*side,pi*radius*radius);
    return 0;
}
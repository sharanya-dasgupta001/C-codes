#include<stdio.h>
int main(){
    int age;
    printf("Enter the age");
    scanf("%d",&age); 
    if (age>18){
        printf("Person is adult\n");
        printf("Can Vote");
    }
    else if (13<age<18)
    {
        printf("Person is teenager");
        printf("Can't Vote");
    }
    else{
        printf("Person is Child");
        printf("Can't Vote\n");
    }

    age>=18 ? printf("adult\n") : printf("not adult\n");
    return 0;
}
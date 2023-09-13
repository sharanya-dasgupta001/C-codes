#include<stdio.h>
#include<string.h>

int main(){
    char password[100];
    scanf("%s",&password);
    char salt[]="123";
    char newpassword[200];
    strcpy(newpassword,password);
    strcat(newpassword,salt);
    puts(newpassword);

    return 0;
}
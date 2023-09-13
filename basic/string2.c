#include<stdio.h>
#include<string.h>

void printString(char arr[]);
void countLength(char arr[]);

int main(){
    // char  college2[50];
    // printf("Enter College Name:");
    // // gets(college2);   //Dangerous
    // fgets(college2,50,stdin);
    // puts(college2);
    // printf("\nLength of string is %d\n",strlen(college2));

    // char oldStr[] = "Old String";
    // char newStr[] = "New String";
    // strcpy(oldStr,newStr);
    // puts(oldStr);

    // char firstString[100]="Hello"; //size must
    // char secondtString[]="world";
    // strcat(firstString,secondtString);
    // puts(firstString);

    char *firstStr="Apple"; 
    char *secondtStr="Banana";
    printf("%d", strcmp(firstStr,secondtStr));
    printf("\n%d\n", strcmp(secondtStr,firstStr));
    firstStr="HHHApple"; 
    secondtStr="HHHBanana";
    printf("%d", strcmp(firstStr,secondtStr));
    printf("\n%d", strcmp(secondtStr,firstStr));

    return 0;
}


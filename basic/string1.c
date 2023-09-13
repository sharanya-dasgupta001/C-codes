#include<stdio.h>
#include<string.h>

void printString(char arr[]);
void countLength(char arr[]);

int main(){
    char name[] = {'S','H','A','R','A','N','Y','A','\0'};
    char firstname[]="SHARANYA";
    char fullname[]="SHARANYA DASGUPTA";
    char college1[50], college2[50];
    printString(name);
    countLength(name);
    printString(firstname);
    countLength(firstname);
    printString(fullname);
    countLength(fullname);
    printf("%s\n",fullname);

    //printf("Enter College Name:");
    //scanf("%s",college1); // scanf( ) cannot input multi-word strings with spaces
    //printf("College name is %s\n",college1);
    
    printf("Enter College Name:");
    // gets(college2);   //Dangerous
    fgets(college2,50,stdin);
    puts(college2);

    char *canChange="Hello World";
    puts(canChange);
    canChange="Hey World"; // Output will change, can be reinitialised
    puts(canChange);
    
    char cannotChange[]="Hello World";
    puts(cannotChange);
    canChange="Hey World"; //Output will not change as char array cannot br reinitialised
    puts(cannotChange);
    return 0;
}

void printString(char arr[]){
    for (int i = 0; arr[i]!='\0' ; i++)
    {
        printf("%c",arr[i]);
    }
    printf("\n");
    
}

void countLength(char arr[]){
    int count=0;
    for (int i = 0; arr[i]!='\0' ; i++)
    {
        count++;
    }
    printf("\nLength of string is %d\n",count);
    
}

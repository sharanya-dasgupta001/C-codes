#include<stdio.h>
#include<string.h>

int main(){
    FILE *fptr;
    fptr = fopen("tests2.txt","r");

    if (fptr==NULL)
    {
        printf("File doesnot exist");
    }
    
    char ch;
    ch=fgetc(fptr);

    while (ch != EOF)
    {
        printf("%c",ch);
        ch=fgetc(fptr);
    }
    
    
    fclose(fptr); //MUST

    return 0;
}
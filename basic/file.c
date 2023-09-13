#include<stdio.h>
#include<string.h>

int main(){
    FILE *fptr;
    fptr = fopen("test.txt","r");
    if (fptr==NULL)
    {
        printf("File doesnot exist");
    }
    char num1[101],num2[101],symbol,character;
    int n1,n2;
    fgets(num1,101,fptr);
    fgets(num2,101,fptr);
    fscanf(fptr,"%c",&symbol);
    printf("%s %s %c",num1,num2,symbol);
    
    fclose(fptr); //MUST

    return 0;
}
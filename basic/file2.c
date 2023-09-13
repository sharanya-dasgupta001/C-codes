#include<stdio.h>
#include<string.h>

int main(){
    FILE *fptr;
    fptr = fopen("tests.txt","r");
    // fptr = fopen("tests.txt","w");

    if (fptr==NULL)
    {
        printf("File doesnot exist");
    }
    
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));
    printf("%c",fgetc(fptr));


    // fputc('M',fptr);
    // fputc('A',fptr);
    // fputc('N',fptr);
    // fputc('G',fptr);
    // fputc('O',fptr);
    // fputc('E',fptr);
    // fputc('S',fptr);

    

    
    fclose(fptr); //MUST

    return 0;
}
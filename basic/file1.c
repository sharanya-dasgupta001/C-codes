#include<stdio.h>
#include<string.h>

int main(){
    FILE *fptr;
    //fptr = fopen("tests.txt","w");
    fptr = fopen("tests.txt","a");

    if (fptr==NULL)
    {
        printf("File doesnot exist");
    }
    
    fprintf(fptr, "%c", 'M');
    fprintf(fptr, "%c", 'A');
    fprintf(fptr, "%c", 'N');
    fprintf(fptr, "%c", 'G');
    fprintf(fptr, "%c", 'O');
    fprintf(fptr, "%c", 'E');
    fprintf(fptr, "%c", 'S');

    
    fclose(fptr); //MUST

    return 0;
}
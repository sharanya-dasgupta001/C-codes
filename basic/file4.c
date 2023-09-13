#include<stdio.h>
#include<string.h>

int main(){
    FILE *fptr;
    fptr = fopen("student.txt","w");

    if (fptr==NULL)
    {
        printf("File doesnot exist");
    }
    
    char name[100];
    float cgpa;
    while (name[0] != '\n')
    {
    scanf("%s",&name);
    scanf("%f",&cgpa);
    fprintf(fptr,"Student Name %s \t",name);
    fprintf(fptr,"CGPA %f",cgpa);
    }
    
    fclose(fptr); //MUST

    return 0;
}
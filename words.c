#include "common.h"
int main(){
    char** lines;
    lines = (char**)malloc(100*sizeof(char*));
    for (int i = 0; i < 100; i++)
    {
        lines[i]=(char*)malloc(100*sizeof(char));
    }
    int j=0;
    for (j = 0; j < 100; j++)
    {
        if(NULL==fgets(lines[j],100,stdin)){
            break;
        }
    }
    for (int i = 0; i < j; i++)
    {
        printf("%d %s",i,lines[i]);
    }
    return 0;
}
// ./a.out<words.txt
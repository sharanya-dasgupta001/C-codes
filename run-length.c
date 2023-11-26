#include "common.h"
int main(){
    char str[100];
    scanf("%s",str);
    int count=1,max_count=0,max_char=str[0];
    for (int i = 0; i < strlen(str); i++)
    {
        if (i==0)
        {
            printf("%c",str[i]);
        }
        else{
            if(str[i]==str[i-1]){
                count++;
            }
            else{
                if(count!=1){
                  printf("%d",count);
                  if(count>max_count){
                    max_count=count;
                    max_char=str[i-1];
                  }
                }
                count=1;
                printf("%c",str[i]);
            }
        }
        
    }
    if(count!=1){
        printf("%d",count);
    }
    printf("\n%c\n",max_char);


    scanf("%s",str);
    for (int i = 0; i < strlen(str); i++)
    {
        if(!isalpha(str[i])){
            for (int j = 1; j < (str[i]-'0'); j++)
            {
                printf("%c",str[i-1]);
            }
            
        }
        else{
            printf("%c",str[i]);
        }
    }
    
    return 0;
    
}
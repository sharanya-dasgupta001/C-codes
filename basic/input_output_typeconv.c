#include<stdio.h>
int main(){
    char ch = 'A';
    int x ;
    
    int i=20;
    float a = 1.757685, b = 1.1;
    long long int c;

    /*
    x=ch;
    printf("%d\n",x); // Implicit Type Conversion
    printf("%d\n",c); // Implicit Type Conversion
    //printf("%d\n",a);
    printf("%d\n", (int)a); // Explicit Type Conversion
    printf("%d\n", (int)b); // EXplicit Type Conversion

    putchar('a');
    puts("abc"); // adds new line at end
    printf("mtc23%-2d",i);
    
    printf("...% <flags><width><precision><length_modifier><type>",... ")
   

   char s1[]="This is Indian Statistical Institute";

   printf("%2.10s",s1); // print upto legth 10
   printf("%.2f\n",a);

   //printf("%d",sizeof(int)); // Warning
   printf("%zd\n",sizeof(ch));
   printf("%zd\n",sizeof(i)); // %zd
   printf("%zd\n",sizeof(a));  
   printf("%zd\n",sizeof(c)); 
    

   char s2[4];
   sprintf(s2,"mtc23%02d.txt",i); // s stores name of txt file
   //snprintf(s2,64,"mtc23%02d.txt",i); 

   printf("%s",s2);
    */

   //char c1; // output only 1
   int c1; // correct output, Reason in copy
   while (EOF != (c1=getchar())) // $ ./a.out<getc-input.txt  and   $ ./a.out<getc-input.txt>new.txt
   {
    putchar(c1);
   }
   

}
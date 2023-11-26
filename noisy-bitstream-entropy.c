/* 
Suppose a noisy bitstream is represented by a sequence of characters from the set {0, 1, ?}. The
special character ? represents a noisy bit whose value is not known, and can either be 0 or 1. For
example, the following is a noisy bitstream.
001?101001?01001?01
Write a program to find out the minimum and maximum possible values of the Shannon entropy of
a noisy bitstream of even length, provided by the user. Recall that the Shannon entropy H(X) of
a bitstream can be computed as follows:
H(X) = − Sum[ Pr (X = i) log2 (Pr (X = i))
        i∈{0,1} 
      and Pr(X=i)>0
      
where Pr (X = i) denotes the occurrence probability of i in the bitstream. The figure below shows
how entropy varies with Pr (X = 1), the probability of occurrence of 1 in a given bitstream.

Input format: The input (to be read from stdin) comprises a sequence of successive characters
from the set {0, 1, ?}. The end of the sequence is marked by a newline. The length of the input
bitstream is not known in advance, but is small enough to be stored in an int.
Output format: The output (to be printed to stdout) should consist of a single line containing two
floating point numbers, corresponding respectively to the minimum and maximum possible values of
Shannon entropy for the given bit string. The values should be rounded off to three decimal places.

Sample input 0: 11111111111111111
Sample output 0: 0.000 0.000
Explanation: There is no noisy bit, and all the bits are the same, so the entropy of the above
bitstream is 0 (fixed and minimum possible value).
Sample input 1: 01110010101100100101
Sample output 1: 1.000 1.000
Explanation: There is no noisy bit, and there are an equal number of 0s and 1s, so the entropy for
this bitstream is 1 (fixed and maximum possible value).
Sample input 2: 011100101011001?0101
Sample output 2: 0.993 1.000
Explanation: If the single noisy bit has the value 0, the bitstream will have an equal number of 0s
and 1s with an entropy of 1; if it has the value 1, the bitstream will have entropy 0.993.
Sample input 3: 1111100000??11111111
Sample output 3: 0.811 0.934
Explanation: If both the noisy bits have the values 0, the bitstream will have entropy 0.934068; if
both of them have the values 1, the bitstream will have entropy 0.811278.
*/

#include "common.h"
#include <math.h>



int main(int ac, char *av[])
{

    int i=0;
    int c;
    float n0=0,n1=0,nqn=0;

    while ('\n' != (c = getchar())) {
    
    	if(c=='0')
    		n0++;
    	if(c=='1')
    		n1++;
    	if(c=='?')
    		nqn++;
      
    
    }
	
    	
    //printf("%f %f %f\n",n0,n1,nqn);
    
    if(nqn==0){
    if((n1==n0)){
    printf("%.3f %.3f",1.000,1.000);}
    if((n1==0)){
    printf("%.3f %.3f",0.000,0.000);}
    if((n0==0)){
    printf("%.3f %.3f",0.000,0.000);}}
	
	else{
	
	float a=n0,b=n1,c=nqn;
		if(n0<n1){
		while((n1!=n0)&&(nqn!=0)){
		n0++;
		nqn--;
		}
		}
		if(n0>n1){
		while((n1!=n0)&&(nqn!=0)){
		n1++;
		nqn--;
		}
		}
		while(nqn>0){
		n1++;
		nqn--;
		if(nqn!=0){
		n0++;
		nqn--;
		}
		}
		
	float t1,t2,hx1,hx2,max,min;
	float sum=n1+n0;

	t1=-((n1)/sum)*((log((n1)/sum))/log(2));
	t2=-((n0)/sum)*((log((n0)/sum))/log(2));
	max = t1+t2;
	
	n0=a;
	n1=b;
	nqn=c;
	
	if(n0<=n1){
	n1+=nqn;
	nqn=0;
	}
	if(n0>n1){
	n0+=nqn;
	nqn=0;
	}
	sum=n1+n0;
	if(n1!=0){t1=-((n1)/sum)*((log((n1)/sum))/log(2));
	}
	else{
	
	 t1=0;}
	if(n0!=0){t2=-((n0)/sum)*((log((n0)/sum))/log(2));
	
	}
	else{
	
	 t2=0;}
	min = t1+t2;
	
	

	printf("%.3f %.3f",min,max);
}	
    

    
    return 0;
}


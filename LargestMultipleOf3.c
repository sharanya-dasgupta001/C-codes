/* 
Given an array of at most 1000 non-negative digits (0–9), find the largest multiple of 3 that can be
formed from these digits.

Input format: The input (to be read from stdin) comprises a sequence of successive digits 0–9.
The end of the sequence is marked by a newline.

Output format: The largest multiple of 3 that can be formed from the digits provided should
be printed to stdout as a single number. Note that this number may be too large to be stored in a
built-in type of C.

Sample input 0: 81760
Sample output 0: 8760
Sample input 1: 198
Sample output 1: 981
Sample input 2: 19234493219
Sample output 2: 9994433211
*/

#include "common.h"


int main(int ac, char *av[])
{
    
    
    int arr[1000],n=0,count[10]={0,0,0,0,0,0,0,0,0,0};
    char c;
    
    while ('\n' != (c = getchar())) {
        arr[n]= c -'0';
        n++;
    }
    


for(int i=0;i<n;i++){
count[arr[i]]++;
}

    	for(int i=0;i<n;i++){
    	for(int k=i+1; k<n; k++){
    		if(arr[i]<arr[k]){
    			int temp = arr[i];
    			arr[i]=arr[k];
    			arr[k]=temp;
    		}
    	}
    }

int sum=0;
 for(int i=0;i<n;i++){
sum+=arr[i];
}

if(sum%3==0){
for(int i=0;i<n;i++){
printf("%d",arr[i]);

}
}




if(sum%3!=0){
int flag=0;
if(sum%3==2){
	if(count[2]!=0){
	count[2]--;
	flag=1;}
	if((flag==0)&&(count[5]!=0)){
	count[5]--;flag=1;}
	if((flag==0)&&(count[8]!=0)){
	count[8]--;flag=1;}
	if((flag==0)&&(count[1]!=0)){
		count[1]--;
		if(count[1]!=0){
		count[1]--;flag=1;}
		if((flag==0)&&(count[4]!=0)){
		count[4]--;flag=1;}
		if((flag==0)&&(count[7]!=0)){
		count[7]--;flag=1;}
	flag=1;}
	if((flag==0)&&(count[4]!=0)){
		count[4]--;
		if(count[4]!=0){
		count[4]--;flag=1;}
		if((flag==0)&&(count[7]!=0)){
		count[7]--;flag=1;}
	flag=1;}
	if((flag==0)&&(count[7]!=0)){
		count[7]--;
		count[7]--;
	flag=1;}
}
flag=0;
if(sum%3==1){
	if(count[1]!=0){
	count[1]--;flag=1;}
	if((flag==0)&&(count[4]!=0)){
	count[4]--;flag=1;}
	if((flag==0)&&(count[7]!=0)){
	count[7]--;flag=1;}
	if((flag==0)&&(count[2]!=0)){
		count[2]--;
		if(count[2]!=0){
		count[2]--;flag=1;}
		if((flag==0)&&(count[5]!=0)){
		count[5]--;flag=1;}
		if((flag==0)&&(count[8]!=0)){
		count[8]--;flag=1;}
	flag=1;}
	if((flag==0)&&(count[5]!=0)){
		count[5]--;
		if(count[5]!=0){
		count[5]--;flag=1;}
		if((flag==0)&&(count[8]!=0)){
		count[8]--;flag=1;}
	flag=1;}
	if((flag==0)&&(count[8]!=0)){
		count[8]--;
		count[8]--;
	flag=1;}
}


 
for(int j=9;j>=0;j--){
	for(int i=0;i<count[j];i++){
	printf("%d",j);
}
}
}
    

    
  
    
    return 0;
}

#include<stdio.h>
#include<math.h>
void merge(int arr[],int p,int q,int r){
    int n1 = q-p+1;
    int n2 = r-p;
    int L[n1+1],R[n2+1];
    for (int i = 0; i < n1; i++)
        L[i] = arr[p+i-1];
    L[n1] = 9999999;
    for (int i = 0; i < n2; i++)
        R[i] = arr[q+i];
    R[n2] = 9999999;
    int i=0,j=0;
    for (int k = 0; k < r; k++)
    {
        if(L[i]<=R[i]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
    }
    return;
}
void MergeSort(int arr[],int p,int r){
    if(p<r){
        int q = floor((p+r)/2);
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
    return;
    
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    MergeSort(arr,1,n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
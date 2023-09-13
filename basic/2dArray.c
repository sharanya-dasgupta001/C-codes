#include<stdio.h>
int main(){

    int **X;        // Number of cols and rows both not fixed
    int *X[10];     // number of rows is fixed at 10
    int (*X)[10];   // Each Element is 10 element arrray i.e., number of column is fixed but number of rows are not fixed 
    int X[20][10];  // Determined rows and columns

}

/* 

CALLING FUNCTION WHERE 2D ARRAY IN ARGUMENT :-

f( int** , int rows , int cols){                    <---- PERMITTED

}

f( int X[][] , int rows , int cols){                <---- NOT PERMITTED

}

f( int X[][10] , int rows , int cols){              <---- PERMITTED

}

________________________________________________________________________

f(int **X,int rows,int cols){           <--- Only works if X is allocated by 2 mallocs

}
int X[100][200]; --> f(X,100,200)   |   <---- This will not work because X[i] means 8*i bytes after X and try to access that
int Y[100][200]; --> f(Y,100,200)   |

*/

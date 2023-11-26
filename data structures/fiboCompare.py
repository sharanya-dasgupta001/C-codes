import time
import math
def MatrixMult(ls1,ls2,size):
    results= [[0 for i in range(size)]for j in range(size)]
    for i in range(size):
        for j in range(size):
            for k in range(size):    
                results[i][j]+=ls1[i][k]*ls2[k][j]
    return results
def fibo(n):
    if n==0:
        return 0
    if n==1:
        return 1
    return fibo(n-1)+fibo(n-2)

n=int(input("Enter n"))

start = time.time()
ls=[0,1]
for i in range(2,n+1):
    ls.append(ls[i-1]+ls[i-2])
print(ls[n])
end = time.time()
print("For Iterative",end-start)

'''start = time.time()
print(fibo(n))
end = time.time()
print("For Recursion-",end-start)'''

start = time.time()
coeff = [[0,1],[1,1]]
coeffcopy = [[0,1],[1,1]]

k = math.floor(math.log2(n))

for i in range(k):
    coeff = MatrixMult(coeff,coeff,2)
k=n-(2**k)
for i in range(k):
    coeff=MatrixMult(coeff,coeffcopy,2)
print(coeff[0][1]*1)
end = time.time()
print("For Matrix",end-start)

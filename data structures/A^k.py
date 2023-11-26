import math
import time

def MatrixMult(ls1,ls2,size):
    results= [[0 for i in range(size)]for j in range(size)]
    for i in range(size):
        for j in range(size):
            for k in range(size):    
                results[i][j]+=ls1[i][k]*ls2[k][j]
    return results


coeff = [[0,1],[1,1]]

n = math.floor(math.log2(k))
print(n)
for i in range(n):
    newls = MatrixMult(newls,newls,size)
k=k-(2**n)
print(k)
for i in range(k):
    newls=MatrixMult(newls,ls,size)

end = time.time()

print(newls)

print(end-start)
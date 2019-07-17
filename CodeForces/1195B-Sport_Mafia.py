import math
 
n, k = list(map(int, input().split()))
delta = 1+4*2*k
 
d = 9+8*(n+k)
res = int((-3+math.sqrt(d))/2)
print(n-res)
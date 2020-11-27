import math

def power(x):
    n = 0
    while 1:
        L = math.log2(x)
        if L == int(L):
            n += L
            break
        n += 1
        if x%2:
            x = 3 * x + 1
        else:
            x //= 2
    return n

class Solution:
    


    def getKth(self, lo: int, hi: int, k: int) -> int:
        l = []
        for x in range(lo, hi+1):
            l.append((power(x), x))
        l = sorted(l)

        return l[k-1][1]
            
            

class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:
            return 1
        neg = n < 0
        n = abs(n)
        if n == 1:
            if neg:
                return 1.0/x
            else:
                return x

        res = 1
        r = n
        while r >= 2:
            i = 2
            z = x*x
            while i*i <= r:
                z = z * z
                i *= 2
            r -= i
            res *= z
        if r:
            res *= x
        
        if neg:
            res = 1.0 / res
        return res


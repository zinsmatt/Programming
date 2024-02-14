class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        def fact(x):
            if x <= 1:
                return 1
            else:
                return x * fact(x-1)
        m -= 1
        n -= 1
        n += m     
        return int(fact(n) / (fact(m) * fact(n-m)))

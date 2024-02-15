class Solution:
    def integerBreak(self, n: int) -> int:
        def test(n, k):
            f = n / k
            res1 = int(f)**(k-1) * (n-int(f)*(k-1))
            res2 = math.ceil(f)**(k-1) * (n-math.ceil(f)*(k-1))
            if math.ceil(f) * (k-1) >= n:
                return int(f)**(k-1) * (n-int(f)*(k-1))
            else:
                return max(res1, res2)

        return max(test(n, i) for i in range(2, n+1))
        

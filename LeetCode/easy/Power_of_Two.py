class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        def solve(x):
            if x == 0:
                return False
            elif x == 1:
                return True
            elif x % 2 != 0:
                return False
            else:
                return solve(x // 2)
        return solve(n)


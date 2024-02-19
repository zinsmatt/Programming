class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        P = int(1e9)+7

        dp = [{} for i in range(n+1)]

        def solve(r, s):
            if r == 0:
                return int(s == target)
            elif s >= target:
                return 0
            else:
                if s in dp[r].keys():
                    return dp[r][s]
                else:
                    temp = 0
                    for i in range(1, k+1):
                        temp = (temp + solve(r-1, s+i)) % P
                    dp[r][s] = temp
                    return temp
        return solve(n, 0)


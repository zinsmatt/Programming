def solve(a, i, b, j, s, k, memo):
    if i == len(a) and j == len(b) and k == len(s):
        return True

    if i == len(a):
        return b[j:] == s[k:]
    if j == len(b):
        return a[i:] == s[k:]

    if memo[i][j] != -1:
        return memo[i][j]
    
    res = False
    if b[j] == s[k] and solve(a, i, b, j+1, s, k+1, memo) or a[i] == s[k] and solve(a, i+1, b, j, s, k+1, memo):
        res = True
    memo[i][j] = int(res)
    return res

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        if len(s1) + len(s2) != len(s3):
            return False
        memo = [[-1] * (len(s2)+1) for _ in range((len(s1)+1))]
        return solve(s1, 0, s2, 0, s3, 0, memo)

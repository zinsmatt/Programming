class Solution:
    def countSubstrings(self, s: str) -> int:
        res = 0
        for i in range(len(s)):
            n = 0
            while i-n>=0 and i+n < len(s) and s[i-n]==s[i+n]:
                res += 1
                n += 1
            if i < len(s)-1:
                l=i
                r=i+1
                while l >= 0 and r < len(s) and s[l] == s[r]:
                    res += 1
                    l -= 1
                    r += 1
                
        return res




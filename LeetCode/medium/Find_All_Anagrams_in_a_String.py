class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        letters = [0] * 26
        ana = [0] * 26

        for c in p:
            ana[ord(c)-ord('a')] += 1

        if len(s) < len(p):
            return []
        res = []
        
        l = 0
        for i in range(len(p)):
            letters[ord(s[i])-ord('a')] += 1
        while l+len(p) <= len(s):
            if letters == ana:
                res.append(l)
            letters[ord(s[l])-ord('a')] -= 1
            if l+len(p) < len(s):
                letters[ord(s[l+len(p)])-ord('a')] += 1
            l += 1
        
        return res

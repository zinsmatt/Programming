def intersection(a, b):
    for i in range(26):
        if a[i] and b[i]:
            return True
    return False

def h(s):
    count = [0] * 26
    for c in s:
        count[ord(c)-ord('a')] += 1
    return count

class Solution:
    def maxProduct(self, words: List[str]) -> int:
        hashes = [h(s) for s in words]
        res = 0
        for i in range(len(hashes)):
            for j in range(i+1, len(hashes)):
                if not intersection(hashes[i], hashes[j]):
                    res = max(res, len(words[i]) * len(words[j]))
        return res

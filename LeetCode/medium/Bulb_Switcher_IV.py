class Solution:
    def minFlips(self, target: str) -> int:
        d = 0
        res = 0
        for i in range(len(target)):
            if int(target[i]) != d:
                d = (d + 1) % 2
                res += 1
        return res
                
            

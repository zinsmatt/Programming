class Solution:


    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        
        n = len(tokens)
        if n == 0:
            return 0
        tokens = sorted(tokens)
        score = 0
        l = 0
        r = n-1
        res = 0
        while l <= r:
            if power >= tokens[l]:
                power -= tokens[l]
                score += 1
                res = max(res, score)
                l += 1
            elif score > 0:
                power += tokens[r]
                score -= 1
                r -= 1
            else:
                break
        return res
     
     



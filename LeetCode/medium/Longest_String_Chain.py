class Solution:
    def longestStrChain(self, words: List[str]) -> int:
        def hash(w):
            h = [0] * 26
            for c in w:
                h[ord(c)-ord('a')] += 1
            return h
        
        def check_pred(wa, wb):
            """ length of wb is length of wa + 1 """
            i, j = 0, 0
            one_diff = 0
            while i < len(wa) and j < len(wb):
                if wa[i] != wb[j]:
                    if one_diff == 0:
                        one_diff = 1
                        j += 1
                    else:
                        return False
                else:
                    i += 1
                    j += 1
            return True
            
        n = len(words)
        pred = [[] for i in range(n)]
        for i in range(n):
            for j in range(n):
                if i != j:
                    if len(words[i]) == len(words[j])-1:
                        if check_pred(words[i], words[j]):
                            pred[j].append(i)
        
        dp = [-1] * n
        def find_longest(i, t, pred):
            if dp[i] != -1:
                return dp[i]
            res = 0
            for p in pred[i]:
                res = max(res, find_longest(p, t+1, pred))
            dp[i] = res+1
            return dp[i]

        res = 1
        for i in range(n):
            res = max(res, find_longest(i, 1, pred))
        return res


        

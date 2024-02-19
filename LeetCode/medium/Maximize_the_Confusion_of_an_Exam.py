class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        def max_subarray(C):
            # max C
            l = 0
            r = 0
            n = 0
            maxC = 0
            while r < len(answerKey):
                if answerKey[r] == C:
                    r += 1
                    maxC = max(maxC, r-l)
                else:
                    if n < k:
                        r += 1
                        maxC = max(maxC, r-l)
                        n += 1
                    else:
                        while l < r and n >= k:
                            if answerKey[l] != C:
                                n -= 1
                            l += 1
            return maxC
        return max(max_subarray('F'), max_subarray('T'))

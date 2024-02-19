class Solution:
    def findOriginalArray(self, changed: List[int]) -> List[int]:
        d = [0] * 100001
        for x in changed:
            d[x] += 1
        if d[0] % 2 != 0:
            return []
        else:
            res = [0] * (d[0]//2)
        for i in range(1, len(d)):
            if d[i] > 0:
                if i*2 >= len(d) or d[i*2] < d[i]:
                    return []
                else:
                    d[i*2] -= d[i]
                    res += [i] * d[i]
                    d[i] = 0

        return res



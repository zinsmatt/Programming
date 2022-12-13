class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        a = [0] * 10001 * 2
        for l, r in intervals:
            l *= 2
            r *= 2
            a[l:(r+1)] = [1] * (r-l+1)
        res = []
        l = -1
        i = 0
        while i < len(a):
            if a[i]:
                if l < 0:
                    l = i
            else:
                if l >= 0:
                    res.append([l//2, (i-1)//2])
                    l = -1
            i += 1

        if l >= 0:
            res.append([l//2, (i-1)//2])    
        return res

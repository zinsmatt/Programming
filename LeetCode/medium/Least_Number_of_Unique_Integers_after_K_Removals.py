class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        d = {}
        for x in arr:
            if x in d.keys():
                d[x] += 1
            else:
                d[x] = 1
        l = sorted(d.items(), key=lambda x:x[1])
        n = k
        i = 0
        while n > 0:
            if l[i][1] > n:
                break
            else:
                n -= l[i][1]
                i += 1
        return len(l)-i

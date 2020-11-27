class Solution:
    def countTriplets(self, arr: List[int]) -> int:
        l = [0]
        for x in arr:
            l.append(l[-1]^x)
        res = 0
        n = len(l)
        for i in range(1, n):
            for j in range(i+1, n):
                for k in range(j, n):
                    if l[j-1]^l[i-1] == l[k]^l[j-1]:
                        res+=1
        return res

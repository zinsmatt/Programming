def count(r):
    i = 0
    while i < len(r) and r[i] == 1:
        i+=1
    return i


class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        scores = [(count(r), i) for i, r in enumerate(mat)]
        scores = sorted(scores)
        res = [s[1] for s in scores[:k]]
        return res

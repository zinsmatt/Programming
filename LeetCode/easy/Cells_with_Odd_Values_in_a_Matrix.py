class Solution:
    def oddCells(self, n: int, m: int, indices: List[List[int]]) -> int:
        g = [[0]*m for i in range(n)]
        for r, c in indices:
            for i in range(n):
                g[i][c] += 1
            for i in range(m):
                g[r][i] += 1
        res = 0
        for l in g:
            for x in l:
                res += x%2
        return res

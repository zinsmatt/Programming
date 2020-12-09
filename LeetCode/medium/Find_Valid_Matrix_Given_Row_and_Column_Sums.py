class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        n = len(rowSum)
        m = len(colSum)
        g = [[0]*m for i in range(n)]
        
        j = 0
        for i in range(n):
            x = rowSum[i]
            while x:
                d = min(x, colSum[j])
                x -= d
                colSum[j] -= d
                g[i][j] = d
                if colSum[j] == 0:
                    j += 1
        return g

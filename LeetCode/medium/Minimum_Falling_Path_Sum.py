class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        m = len(matrix[0])
        for i in range(1, len(matrix)):
            for j in range(m):
                r = min(matrix[i-1][max(0, j-1):min(m, j+1+1)])
                matrix[i][j] += r
        
        return min(matrix[-1])

class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        row_mins = []
        m = len(matrix)
        n = len(matrix[0])
        
        row_mins = [min(matrix[r]) for r in range(m)]
        col_max = []
        
        for c in range(n):
            maxi = -9899999999999999999
            for r in range(m):
                if matrix[r][c] > maxi:
                    maxi = matrix[r][c]
            col_max.append(maxi)
        res = []
        for r in range(m):
            for c in range(n):
                x = matrix[r][c] 
                if x == row_mins[r] and x == col_max[c]:
                    res += [x]
        return res
                    
                
                

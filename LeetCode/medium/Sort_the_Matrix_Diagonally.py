class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        
        h, w = len(mat), len(mat[0])
        res = [[0]*w for i in range(h)]
        
        for x in range(w):
            coords = []
            values = []
            r=0
            c=x
            while r < h and c < w:
                coords.append([r, c])
                values.append(mat[r][c])
                c += 1
                r += 1
            values = sorted(values)
            i = 0
            for r, c in coords:
                res[r][c] = values[i]
                i += 1
                
                
        for y in range(1, h):
            coords = []
            values = []
            r=y
            c=0
            while r < h and c < w:
                coords.append([r, c])
                values.append(mat[r][c])
                c += 1
                r += 1
            values = sorted(values)
            i = 0
            for r, c in coords:
                res[r][c] = values[i]
                i += 1
                
        return res

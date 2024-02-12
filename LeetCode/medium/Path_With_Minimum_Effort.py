class Solution:
    def minimumEffortPath(self, heights: List[List[int]]) -> int:
        n = len(heights)
        m = len(heights[0])

        def possible(i, j, k, done):
            done[i][j] = True
            if i == n-1 and j == m-1:
                return True
            
            ij = [(-1, 0), (0, -1), (1, 0), (0, 1)]
            ret = False
            for ii, jj in ij:
                if i+ii >= 0 and i+ii < n and j+jj >= 0 and j+jj < m:
                    if not done[i+ii][j+jj] and abs(heights[i][j]-heights[i+ii][j+jj]) <= k:
                        ret = ret or possible(i+ii, j+jj, k, done)
            return ret

        l = 0
        r = 1000000
        while l < r:
            mid = (l+r) // 2
            temp = [[False]*m for i in range(n)]
            p = possible(0, 0, mid, temp)
            if p:
                r = mid
            else:
                l = mid+1
        return l

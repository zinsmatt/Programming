class Solution:
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        l = sorted(tasks, key=lambda x: (x[1]-x[0], x[1]), reverse=True)
        
        mini = sum(a[0] for a in l)
        x = mini
        res = mini
        for a in l:
            d = max(0, a[1]-x)
            res += d
            x += d
            x -= a[0]
        return res
            
            
        

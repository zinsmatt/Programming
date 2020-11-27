def sq(r, c, n):
    m = n+2
    
    s = (r, c+1)
    l = [s]
    for i in range(m-1-1):
        prev = l[-1]
        l.append((prev[0]+1, prev[1]))
    for i in range(m-1):
        prev = l[-1]
        l.append((prev[0], prev[1]-1))
    for i in range(m-1):
        prev = l[-1]
        l.append((prev[0]-1, prev[1]))
    for i in range(m-1):
        prev = l[-1]
        l.append((prev[0], prev[1]+1))
    return l
        
    
    

class Solution:
    def spiralMatrixIII(self, R: int, C: int, r0: int, c0: int) -> List[List[int]]:
        l = [(r0, c0)]
        for t in range(1, 2 * max(R, C) + 2, 2):
            l2 = sq(*l[-1], t)
            l.extend(l2)
        l_filt = filter(lambda x:x[0]>=0 and x[0]<R and x[1]>=0 and x[1] < C, l)    
        return l_filt
        

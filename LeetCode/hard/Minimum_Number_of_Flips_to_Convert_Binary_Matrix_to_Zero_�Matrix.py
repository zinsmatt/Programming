import copy
def generate(x, n):
    if len(x)==n:return [x]
    else:
        return generate(x+"0", n), generate(x+"1", n) 
    
def serialize(m):
    return "".join(map(lambda x:"".join(map(str,x)), m))

def flip(m, r, c):
    m[r][c] = (m[r][c]+1)%2
    if r > 0:
        m[r-1][c] = (m[r-1][c]+1)%2
    if c > 0:
        m[r][c-1] = (m[r][c-1]+1)%2
    if r < len(m) - 1:
        m[r+1][c] = (m[r+1][c]+1)%2
    if c < len(m[0]) - 1:
        m[r][c+1] = (m[r][c+1]+1)%2
    return m
        
class Solution:

    def minFlips(self, mat: List[List[int]]) -> int:
        
        m = len(mat)
        n = len(mat[0])
        
        possibles = generate("", n*m)
        done = {}
        
        s = serialize(mat)
        count = [0]
        q = [mat]
        
        while len(q):
            x = q[0]
            c = count[0]
            q = q[1:]
            count = count[1:]
            s = serialize(x)

            if "1" not in s:
                return c

            if s in done.keys():
                continue

            done[s] = 1
            for i in range(m):
                for j in range(n):
                    nouv = flip(copy.deepcopy(x), i, j)
                    q += [nouv]
                    count += [c + 1]
        return -1
            
            
            
        
        

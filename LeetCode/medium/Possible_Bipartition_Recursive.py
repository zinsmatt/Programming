def colorize(x, edges, done, colors, col):
    if done[x]:
        return colors[x] == col
    colors[x] = col
    done[x] = True
    new_col = (col+1)%2
    res = True
    for e in edges[x]:
        res = res and colorize(e, edges, done, colors, new_col)
    return res

class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        colors = [-1] * (n+1)
        done = [False] * (n+1)
        
        edges = [[] for i in range(n+1)]
        for a, b in dislikes:
            edges[a].append(b)
            edges[b].append(a)

        for i in range(1, n+1):
            if done[i]:
                continue
            if not colorize(i, edges, done, colors, 0):
                return False
        return True

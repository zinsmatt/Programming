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
            q = [i]
            colors[i] = 0
            done[i] = True
            while len(q):
                x = q[0]
                q = q[1:]
                new_col = (colors[x] + 1) % 2
                for e in edges[x]:
                    if done[e]:
                        if colors[e] != new_col:
                            return False
                    else:
                        done[e] = True
                        colors[e] = new_col
                        q.append(e)
        return True

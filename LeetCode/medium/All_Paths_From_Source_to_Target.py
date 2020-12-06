class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        res = []
        q = [0]
        paths = [[]]
        while len(q):
            x = q[0]
            q = q[1:]
            p = paths[0]
            paths = paths[1:]
            p.append(x)
            if x == len(graph)-1:
                res.append(p)
                continue
            
            for e in graph[x]:
                q.append(e)
                paths.append(p.copy())
        return res

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        wedges = [[] for i in range(n)]
        for a, b in edges:
            wedges[a].append(b)
            wedges[b].append(a)

        done = [False] * n
        def find(cur, target):
            if cur == target:
                return True
            elif done[cur]:
                return False
            else:
                done[cur] = True
                res = False
                for e in wedges[cur]:
                    res = res or find(e, target)
                return res

        return find(source, destination)

        
        

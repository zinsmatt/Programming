class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        q = [["", 0, n]]
        res = []
        while len(q) > 0:
            s, l, m = q[0]
            q.pop(0)
            if len(s) == n*2:
                res.append(s)
            else:
                if l == 0:
                    if m > 0:
                        q.append([s+"(", l+1, m-1])
                elif l < n:
                    if m > 0:
                        q.append([s+"(", l+1, m-1])
                    q.append([s+")", l-1, m])
                else:
                    q.append([s+")", l-1, m])
        return res





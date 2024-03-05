class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        
        def solve(cur, no, l):
            if len(cur) == n*2:
                res.append(cur)
            else:
                if l == 0:
                    if no > 0:
                        solve(cur+"(", no-1, l+1)
                elif l == n:
                    solve(cur+")", no, l-1)
                else:
                    if no > 0:
                        solve(cur+"(", no-1, l+1)
                    solve(cur+")", no, l-1)
        res = []
        solve("", n, 0)
        return res


def solve(e):
    x = e[0]
    e = e[1:]
    if x not in "+-/*":
        return int(x), e
    else:
        o0, e = solve(e)
        o1, e = solve(e)
        if x == "+":
            res = o1 + o0
        elif x == "-":
            res = o1 - o0
        elif x == "/":
            res = abs(o1) // abs(o0)
            if o0*o1 < 0:
                res *= -1
        else:
            res = o1 * o0
        return res, e


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        res, e = solve(tokens[::-1])
        return res

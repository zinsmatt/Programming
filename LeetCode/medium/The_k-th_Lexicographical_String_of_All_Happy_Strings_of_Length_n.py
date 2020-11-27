
def generate(l, n):
    if len(l) == n:
        return [l]

    if l[-1] == 'a':
        return generate(l+"b", n) + generate(l+"c", n)
    if l[-1] == 'b':
        return generate(l+"a", n) + generate(l+"c", n)
    if l[-1] == 'c':
        return generate(l+"a", n) + generate(l+"b", n)
        
class Solution:
    def getHappyString(self, n: int, k: int) -> str:
        k -= 1
        a = generate("a", n)
        b = generate("b", n)
        c = generate("c", n)
        l = sorted(a+b+c)

        if k < len(l):
            return  l[k]
        else:
            return ""

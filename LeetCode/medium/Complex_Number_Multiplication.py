def s(x):
    a, b = x.split('+')
    return int(a), int(b.replace("i", ""))

class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        a1, a2 = s(a)
        b1, b2 = s(b)
        real = a1*b1-a2*b2
        img = a1*b2+a2*b1
        return "%d+%di" % (real, img)

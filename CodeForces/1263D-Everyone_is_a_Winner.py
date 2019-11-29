import math
t = int(input())
for i in range(t):
    n = int(input())
 
    x = 1
    s = set()
    s.add(0)
    s.add(1)
    while x < n // 2 + 1:
        r, d = n%x, n//x
        x += max(1, r // d)
        s.add(d)
    print(len(s))
    print(" ".join(map(str, sorted(list(s)))))
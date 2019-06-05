n, a, x, b, y = list(map(int, input().split()))

ok = 2
good = False
while 1:
    a = a+1 if a < n else 1
    b = b-1 if b > 1 else n
    if a == b:
        good = True
        break
    if a == x:
        break
    if b == y:
        break
if good:
    print("YES")
else:
    print("NO")
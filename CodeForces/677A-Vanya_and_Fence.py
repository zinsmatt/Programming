n, f = list(map(int, input().split()))
res = 0
for h in list(map(int, input().split())):
    if h > f:
        res += 2
    else:
        res += 1
print(res)

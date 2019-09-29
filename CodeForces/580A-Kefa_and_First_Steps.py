n = int(input())
a = list(map(int, input().split()))

res = 0
prev = a[0]
cur = 0
for x in a:
    if x >= prev:
        cur += 1
    res = max(res, cur)
    if x < prev:
        cur = 1
    prev = x
print(res)

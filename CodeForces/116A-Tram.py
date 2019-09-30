n = int(input())
c = 0
res = 0
for i in range(n):
    a, b = list(map(int, input().split()))
    c = max(c-a, 0)
    c += b
    res = max(res, c)
print(res)
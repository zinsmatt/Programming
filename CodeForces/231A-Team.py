n = int(input())
res = 0
for i in range(n):
    s = list(map(int, input().split()))
    if sum(s) >= 2:
        res += 1
print(res)
n = int(input())
f = list(map(lambda x: int(x)-1, input().split()))
res = [0] * n
for i in range(n):
    res[f[i]] = i

print(" ".join(map(lambda x: str(x + 1), res)))
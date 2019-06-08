n = int(input())
res = 0
for k in range(1, n//2+1):
    if (n-k) % k == 0:
        res += 1
print(res)
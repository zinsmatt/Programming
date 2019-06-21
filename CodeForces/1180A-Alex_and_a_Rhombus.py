n = int(input())
res = 1
for i in range(2, n+1):
    res += (i*2)+(i-2)*2
print(res)
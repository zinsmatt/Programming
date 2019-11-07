k = int(input())
for i in range(k):
    n = int(input())
    a = list(map(int, input().split()))
    c = [0] * (n+1)
    for v in a:
        c[v] += 1
    res = 0
    j = n
 
    while j > 0:
        if j < len(c)-1:
            c[j] = c[j] + c[j+1]
        if c[j] >= j:
            res = max(res, j)
        j -= 1
    print(res)
    
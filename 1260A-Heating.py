n = int(input())
for i in range(n):
    c, s = list(map(int, input().split()))
    q = s // c
    r = s % c
    res= (c-r)* (q*q) + r * (q+1)**2
    print(res)
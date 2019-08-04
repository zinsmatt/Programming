n, q = list(map(int, input().split()))
a = []
for i in range(n):
    a.append(input())
s = list(map(int, input().split()))
 
 
res = 0
for i in range(q):
    t = [0] * 5
    for j in range(n):
        t[ord(a[j][i])-ord('A')] += 1
    res += s[i] * max(t)
print(res)
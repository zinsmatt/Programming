n = int(input())
a = list(map(int, input().split()))
x = a[0]
res = [1]
total = sum(a)
for i in range(1, n):
    if a[0]>=2*a[i]:
        x += a[i]
        res.append(i+1)
if total-x < x:
    print(len(res))
    print(" ".join(map(str, res)))
else:
    print(0)
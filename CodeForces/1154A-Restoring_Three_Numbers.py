n = list(map(int, input().split()))
maxi = 0
max_idx = 0
for i in range(4):
    if n[i] > maxi:
        maxi = n[i]
        max_idx = i
res = []
for i in range(4):
    if i != max_idx:
        res.append(maxi - n[i])
print(res[0], res[1], res[2])

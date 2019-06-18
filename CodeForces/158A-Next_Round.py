n, k = list(map(int, input().split()))
scores = sorted(list(map(int, input().split())))[::-1]
k -= 1
while k < n-1 and scores[k] == scores[k+1]:
    k += 1
res = sum([1 if s > 0 else 0 for s in scores[:k+1]])
print(res)
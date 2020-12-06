
nr, nc = map(int, input().split())
m = []
for i in range(nr):
   m.append(list(map(int, input().split())))
   # print(m[-1])


p = [[0]*nc for i in range(nr)]
p[0] = m[0]
best = 0
for c in range(nc):
    p[0][c] = (m[0][c]+1)%2
    best = max(best, p[0][c])

for r in range(1, nr):
    p[r][0] = (m[r][0]+1)%2
    best = max(best, p[r][0])


for r in range(1, nr):
   for c in range(1, nc):
       if m[r][c] == 1:
           continue
       else:
           p[r][c] = min(p[r-1][c-1], p[r-1][c], p[r][c-1]) + 1
           best = max(best, p[r][c])

print(best)


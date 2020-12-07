
n = int(input())
a = []
for i in range(n):
    l, r = map(int, input().split())
    a.append((l, r))   
    

before = {}
a_left = sorted(a)
index = 0
for l, r in a_left:
    if l not in before.keys():
        before[l] = index
    index += 1
index = 0
before2 = {}
a_right = sorted(a, key=lambda x:x[1])
for l, r in a_right:
    if r not in before2.keys():
        before2[r] = index
    else:
        before2[r] += 1
    index += 1
res = 0
# count the nb of manteau which starts striclty before l(m)
# count the nb of manteau which ends before or at r(m)
# the result is the max difference
for l, r in a:
    r = before2[r]-before[l]
    res = max(res, r)
print(res)
        

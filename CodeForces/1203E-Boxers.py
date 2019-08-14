n = int(input())
w = sorted(list(map(int, input().split())))
 
def f(x, res):
    if x > res[-1] or x != res[-1] and x != res[-2]:
        res.append(x)
        return 1
    return 0
    
i = 0
res = [0, 0]
while i < n:
    pred = w[i]
    c = 0
    while i < n and pred == w[i]:
        i += 1
        c += 1
    nb = 0
    for s in [-1, 0, 1]:
        nb += f(pred+s, res) 
        if nb == c:
            break
 
print(len(res)-2
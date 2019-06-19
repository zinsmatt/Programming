n = int(input())
s = sorted(list(map(int, input().split())))


a = 0
b = n-1
res = 0
cur = 0
while  a < b:
    if s[a]+s[b] <= 4-cur:
        cur += s[a]+s[b]
        a += 1
        b -= 1
    else:
        if s[b] <= 4-cur:
            cur += s[b]
            b -= 1
        elif s[a] <= 4-cur:
            cur += s[a]
            a += 1
        else:
            res += 1
            cur = 0
if a == b:
    if s[a] > 4-cur:
        res += 2
    else:
        res += 1
else:
    res += 1
print(res)
        
    

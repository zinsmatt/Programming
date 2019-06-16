def calc(s, a):
    return int(s[:a])+int(s[a:])

n =int(input())
s = input()

if n % 2 == 0:
    if s[n // 2] != '0':
        print(calc(s, n//2))
    else:
        a = n//2 -1 
        b = n//2
        while s[a] == '0' and s[b] == '0':
            a -= 1
            b += 1
        res = -1
        if s[a] != '0' and a > 0:
            res = calc(s, a)
        if s[b] != '0':
            if res < 0:
                res = calc(s, b)
            else:
                res = min(res, calc(s, b))
        print(res)
else:
    if s[n//2] != '0':
        res = calc(s, n//2)
        if s[n//2+1] != '0':
            res = min(res, calc(s, n//2+1))
            
        print(res)
    else:
        a = n//2-1
        b = n//2+1
        while s[a] == '0' and s[b] == '0':
            a -= 1
            b += 1
        res = -1
        if s[a] != '0' and a > 0:
            res = calc(s, a)
        if s[b] != '0':
            if res < 0:
                res = calc(s, b)
            else:
                res = min(res, calc(s, b))
        print(res)
n = int(input())
for i in range(n):
    a, b = list(map(int, input().split()))
    if a == b:
        print(0)
    else:
        d = abs(b-a)
        if d == 1:
            print(1)
        elif d < 5:
            print(d%2 + d//2)
        else:
            q = int(round(d/5))
            if b < a and a-q*5 < 0:
                q-=1
            
            d = abs(d-q*5)
            print(d%2 + d//2 + q)
            
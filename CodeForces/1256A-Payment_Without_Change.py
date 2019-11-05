    n = int(input())
     
    for i in range(n):
        ok = False
        a, b, n, s = list(map(int, input().split()))
        
        r = s // n
        s -= n * min(a, r)
        if s > b:
            print("NO")
        else:
            print("YES")
        
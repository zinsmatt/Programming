q = int(input())
for i in range(q):
    n, k = list(map(int, input().split()))
    if k == 1:
        print(n)
        
    nb = 0
    while n != 0:
        if n % k == 0:
            n //= k
            nb += 1
        else:
            r = n % k
            nb += r
            n -= r
    print(nb)
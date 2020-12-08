n = int(input())
cont = [0] + list(map(int, input().split()))




    
m = int(input())
queries = list(map(int, input().split()))
    
for q in queries:
    l = [q]
    i = 0
    while q != 0:
        q = cont[q]
        if q != 0:
            l.append(q)
    print(*l[::-1])

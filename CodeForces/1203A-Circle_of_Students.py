q = int(input())
for i in range(q):
    n = int(input())
    l = list(map(int, input().split()))
    if n <= 2:
        print("YES")
    else:
        c = True
        uc = True
        for i in range(n):
            if l[(i+1)%n] - l[i] == 1:
                uc = False
            elif l[(i+1)%n] - l[i] == -1:
                c = False
            elif l[(i+1)%n] - l[i] == -(n-1):
                uc = False
            elif l[(i+1)%n] - l[i] == (n-1):
                c = False
            else:
                uc = False
                c = False
                break
            if not uc and not c:
                break
                
        if uc or c:
            print("YES")
        else:
            print("NO")

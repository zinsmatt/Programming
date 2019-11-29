import math
n = int(input())
for i in range(n):
    a, b = list(map(int, input().split()))
    if a==1 and b == 1:
        print("NO")
        continue
    
    if a>2*b or b>2*a:
        print("NO")
        continue
    
    while a != b:
        e = int(math.ceil((abs(a-b)/2)))
        if a < b:
            a -= e
            b -= 2*e
        else:
            a -= 2*e
            b -= e
    if a == 0 or a %3 == 0:
        print("YES")
    else:
        print("NO")
n = int(input())
xx = set()
yy = set()
for i in range(n):
    x, y = list(map(int, input().split()))
    xx.add(x)
    yy.add(y)
    
print(min(len(xx), len(yy)))
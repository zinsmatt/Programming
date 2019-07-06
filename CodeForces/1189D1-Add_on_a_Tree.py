n = int(input())
edges = [0] * (n)
for i in range(n-1):
    a, b = list(map(int, input().split()))
    edges[a-1] +=1
    edges[b-1] +=1
    
if 2 in edges:
    print("NO")
else:
    print("YES")

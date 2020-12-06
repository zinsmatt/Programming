n, m = map(int, input().split())

av = [0] * n
for i in range(m):
   p = int(input())
   for j in range(p):
      b, d = map(int, input().split())
      if av[b] <= i:
         av[b] = i + d
         print(1)
      else:
         print(0)
    
     

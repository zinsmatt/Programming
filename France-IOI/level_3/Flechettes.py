n = int(input())

l = [chr(96)] * (2*n-1)
res = []
for i in range(n):
   for j in range(i, len(l)-i):
      l[j] = chr(ord(l[j])+1)
   res.append(l.copy())
  
for l in res+res[:-1][::-1]:
   print("".join(l))
      



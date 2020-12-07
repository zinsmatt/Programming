

n = int(input())
x = 1
i = 1
while x < n:
   i += 1
   x *= i

if x > n:
   x //= i
   i -= 1
   
res = [0] * (i+1)

while n:
   if x <= n:
      nb = n//x
   else:
      nb = 0
   n -= nb * x
   res[i] += nb
   x //= i
   i -= 1
   
   
print(*res[1:])

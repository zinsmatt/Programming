n = int(input())
m = int(input())

a = [0] * n
score = [0] * n
maxi = 0
maxi_i = -1
for i in range(m):
   x, d = map(int, input().split())
   
   if i == m-1:
      break
   a[x-1] += d
   if a[x-1] == maxi:
      maxi_i = -1   
   elif a[x-1] > maxi:
      maxi_i = x-1
      maxi = a[x-1]

   if maxi_i >= 0:
      score[maxi_i] += 1
   
i = 0
i_max = 0
score_max = 0
while i < n:
   if score[i] > score_max:
      score_max = score[i]
      i_max = i
   i += 1
print(i_max+1)
   
  
   
   

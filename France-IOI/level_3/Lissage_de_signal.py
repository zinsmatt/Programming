n = int(input())
a = [0] * n
md = float(input())
for i in range(n):
   a[i] = float(input())
   
def smooth(arr):
   nouv = arr.copy()
   for i in range(1, len(arr)-1):
      nouv[i] = (arr[i-1]+arr[i+1])/2   
   return nouv
   
def max_diff(arr):
   max_d = 0
   for i in range(len(arr)-1):
      max_d = max(max_d, abs(arr[i]-arr[i+1]))
   return max_d

res = 0
while max_diff(a) > md:
   a = smooth(a)
   res += 1
   

print(res)

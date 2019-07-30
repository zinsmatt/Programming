n, x, y = list(map(int, input().split()))
a = list(map(int, input().split()))
 
for i in range(0, n):
    if max(0, i-x) < i:
        m1 = min(a[max(0, i-x):i])
    else:
        m1 = 10**9 + 1
    
    if i+1 < min(i+y, n)+1 and i+1 < n:
        m2 = min(a[i+1:min(i+y, n-1)+1])
    else:
        m2 = 10**9 + 1
        
    if a[i] < m1 and a[i] < m2:
        print(i+1)
        break
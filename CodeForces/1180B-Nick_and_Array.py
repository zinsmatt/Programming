n = int(input())
arr = list(map(int, input().split()))
for i in range(n):
    if arr[i] >= 0:
        arr[i] = -arr[i]-1
    
if n % 2 == 1:
    min_idx = 0
    min_val = arr[0]
    for i in range(n):
        if arr[i] < min_val:
            min_val = arr[i]
            min_idx = i
    arr[min_idx] = -arr[min_idx] - 1
    
print(" ".join(map(str, arr)))
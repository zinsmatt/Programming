n = int(input())
arr = list(map(int, input().split()))
if arr[0] % 2 == arr[1] % 2:
    target = (arr[0]%2+1)%2
else:
    if arr[1] % 2 == arr[2] % 2:
        target = arr[0] % 2
    else:
        target = arr[1] % 2
for i, c in enumerate(arr):
    if c % 2 == target:
        print(i+1)

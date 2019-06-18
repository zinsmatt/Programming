n = int(input())
arr = list(map(int, input().split()))
nbOdd = 0
nbEven = 0
for x in arr:
    if x % 2 == 1:
        nbOdd = 1
    else:
        nbEven = 1
        
if nbOdd and nbEven:
    print(" ".join(map(str, sorted(arr))))
else:
    print(" ".join(map(str, arr)))
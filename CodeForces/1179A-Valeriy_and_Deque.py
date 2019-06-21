n, q = list(map(int, input().split()))

arr = list(map(int, input().split()))

maxi = max(arr[0], arr[1])
reste = [min(arr[0], arr[1])]

hist_maxi = [maxi]
for i in range(2, n):
    if arr[i] > maxi:
        reste.append(maxi)
        maxi = arr[i]
    else:
        reste.append(arr[i])
    hist_maxi.append(maxi)



for qi in range(q):
    r = int(input()) - 1
    if r == 0:
        print(arr[0], arr[1])
        continue
    
    if r > n-2:
        print(maxi, reste[r%len(reste)])
    else:
        if hist_maxi[r-1] == hist_maxi[r]:
            print(hist_maxi[r], reste[r])
        else:
            print(reste[r], hist_maxi[r])
            
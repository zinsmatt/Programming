n = int(input())
a = sorted(list(map(int, input().split())))
 
maxi = max(a)
s = sum(a)
if s % 2 == 0 and maxi <= s - maxi:
    print("YES")
else:
    print("NO")
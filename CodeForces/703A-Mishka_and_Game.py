
n = int(input())
res = 0
for i in range(n):
    a, b = list(map(int, input().split()))
    if a > b:
        res -= 1
    elif a < b:
        res += 1
if res < 0:
    print("Mishka")
elif res > 0:
    print("Chris")
else:
    print("Friendship is magic!^^")
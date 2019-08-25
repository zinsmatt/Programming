t = int(input())
for k in range(t):
    a, b, n = list(map(int, input().split()))
    res = [a, b, a ^ b]
    print(res[n % 3])
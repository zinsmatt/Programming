import math
n, m, a = list(map(int, input().split()))
print(int(math.ceil(float(n)/a)) * int(math.ceil(float(m)/a)))
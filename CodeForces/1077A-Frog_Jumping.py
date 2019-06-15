import math as m
t = int(input())
for i in range(t):
    a, b, k = list(map(int, input().split()))
    nb_a = k // 2 + k % 2
    nb_b = k // 2
    print(nb_a*a-nb_b*b)
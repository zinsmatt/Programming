a, b = list(map(int, input().split()))
nb = 0
while a <= b:
    a *= 3
    b *= 2
    nb += 1
print(nb)
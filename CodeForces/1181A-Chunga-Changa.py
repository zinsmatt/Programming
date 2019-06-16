x, y, z = list(map(int, input().split()))
nb = 0
nb += x //z
x = x % z
nb += y // z
y = y % z

res = 0
if x + y >= z:
    res = z - max(x, y)
    nb += 1
print(nb, res)
x, y = 0, 0
for r in range(5):
    row = list(map(int, input().split()))
    if 1 in row:
        x = row.index(1)
        y = r
print(abs(x-2) + abs(y-2))

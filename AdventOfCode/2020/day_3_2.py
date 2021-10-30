with open("data_day_3.txt") as fin:
    data = fin.readlines()
data = [l.strip() for l in data]

def solve(dx, dy):
    res = 0
    i, j = 0, 0
    for i in range(0, len(data), dy):
        res += data[i][j] == '#'
        j = (j + dx) % len(data[0])
    return res

print(solve(1, 1) * solve(3, 1) * solve(5, 1) * solve(7, 1) * solve(1, 2))
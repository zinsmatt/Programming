with open("data_day_3.txt") as fin:
    data = fin.readlines()
data = [l.strip() for l in data]

res = 0
i, j = 0, 0
for i in range(len(data)):
    res += data[i][j] == '#'
    j = (j + 3) % len(data[0])

print(res)
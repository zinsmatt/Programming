with open("data_day_1.txt", "r") as fin:
    data = fin.readlines()

l = list(map(int, data))

for i in range(len(l)):
    for j in range(i+1, len(l)):
        if l[i] + l[j] == 2020:
            print(l[i]*l[j])


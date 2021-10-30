with open("data_day_2.txt") as fin:
    data = fin.readlines()

res = 0
for l in data:
    policy, letter, pwd = l.split()
    letter = letter[0]
    a, b = map(int, policy.split("-"))
    res += ((pwd[a-1] == letter) + (pwd[b-1] == letter)) == 1

print(res)
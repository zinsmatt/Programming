with open("data_day_2.txt") as fin:
    data = fin.readlines()
res = 0
for l in data:
    policy, letter, pwd = l.split()
    letter = letter[0]
    mini, maxi = map(int, policy.split("-"))
    count = 0
    for c in pwd:
        if c == letter:
            count += 1
    res += count >= mini and count <= maxi
print(res)
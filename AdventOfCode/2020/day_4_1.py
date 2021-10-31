with open("data_day_4.txt") as fin:
    data = fin.readlines()

needed = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]# , "cid"]

res = 0
fields_l = []
for l in data:
    l = l.strip()
    if len(l) == 0:
        fields = set(fields_l)
        res += sum(n in fields for n in needed) == 7
        fields_l = []
    else:
        fields_l.extend([x.split(":")[0] for x in l.split()])

# last line
fields = set(fields_l)
res += sum(n in fields for n in needed) == 7

print(res)



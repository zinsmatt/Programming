with open("data_day_4.txt") as fin:
    data = fin.readlines()

needed = ["byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"]# , "cid"]
ecl_ = set(["amb", "blu", "brn", "gry", "grn", "hzl", "oth"])

def check(f, v):
    if f == "byr":
        if len(v) != 4:
            return False
        try:
            x = int(v)
            return x >= 1920 and x <= 2002
        except:
            return False
    elif f == "iyr":
        if len(v) != 4:
            return False
        try:
            x = int(v)
            return x >= 2010 and x <= 2020
        except:
            return False
    elif f == "eyr":
        if len(v) != 4:
            return False
        try:
            x = int(v)
            return x >= 2020 and x <= 2030
        except:
            return False
    elif f == "hgt":
        try:
            end = v[-2:]
            x = int(v[:-2])
            return x >= 150 and x <= 193 and end == "cm" or x >= 59 and x <= 76 and end=="in"
        except:
            return False
    elif f == "hcl":
        return v[0] == "#" and len(v) == 7 and all(ord(x) >= ord('0') and ord(x) <= ord('9') or ord(x) >= ord('a') and ord(x) <= ord('f') for x in v[1:])
    elif f == "ecl":
        return v in ecl_
    elif f == "pid":
        return sum(ord(x) >= ord('0') and ord(x) <= ord('9') for x in v) == 9
    return 0

res = 0
fields_l = []
for l in data:
    l = l.strip()
    if len(l) == 0:
        fields = dict(fields_l)
        res += sum(check(f, v) for f, v in fields.items()) == 7
        fields_l = []
    else:
        fields_l.extend([x.split(":") for x in l.split()])

# last line
fields = dict(fields_l)
res += sum(check(f, v) for f, v in fields.items()) == 7

print(res)



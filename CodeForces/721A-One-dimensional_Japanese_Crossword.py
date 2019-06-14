n = int(input())
s = input()
res = []
for group in s.split("W"):
    if len(group) > 0:
        res.append(len(group))
print(len(res))
print(" ".join(map(str, res)))
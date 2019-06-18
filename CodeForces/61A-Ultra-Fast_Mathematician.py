from functools import reduce
a = input()
b = input()
res = ""
for x, y in zip(a, b):
    res += "1" if x != y else "0"
print(res)
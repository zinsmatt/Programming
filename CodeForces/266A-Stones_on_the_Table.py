n = int(input())
s = input()
res = 0
pred = ""
for c in s:
    if c == pred:
        res += 1
    pred = c
print(res)

n = int(input())
s = input()
i = 0
res = []
while i < len(s):
    res.append(s[i])
    i += (len(res)+1)
print("".join(res))

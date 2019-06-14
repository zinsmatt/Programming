n = int(input())
s = ""
for i in range(n):
    s += input()
res = 1
for i in range(1, len(s)):
    if s[i] == s[i-1]:
        res += 1
print(res)
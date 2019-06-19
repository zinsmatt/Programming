s = input()
target = "hello"
a = 0
for c in s:
    if c == target[a]:
        a += 1
    if a >= len(target):
        break
if a == len(target):
    print("YES")
else:
    print("NO")

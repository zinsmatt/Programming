input()
s = input()
a, d = 0, 0
for c in s:
    if c == 'A':
        a += 1
    else:
        d += 1
if a < d:
    print("Danik")
elif a > d:
    print("Anton")
else:
    print("Friendship")

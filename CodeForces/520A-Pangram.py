input()
s = input().lower()
occur = [0] * 26
for c in s:
    occur[ord(c)-ord('a')] += 1
ok = 1
for c in occur:
    ok *= c
print("YES" if ok else "NO")

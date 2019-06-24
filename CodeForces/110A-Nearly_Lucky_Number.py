n = int(input())
nb = sum([1 if c in "47" else 0 for c in str(n)])
ok = True
for c in str(nb):
    if c not in "47":
        ok = False
        break
print("YES" if ok else "NO")
n = int(input())
ok = False
bus = []
for i in range(n):
    row = input()
    if not ok and row[0:2]=="OO":
        row = "++" + row[2:]
        ok = True
    elif not ok and row[3:]=="OO":
        row = row[:3] + "++"
        ok = True
    bus.append(row)
if ok:
    print("YES")
    print("\n".join(bus))
else:
    print("NO")
s = input()
a, r = s.split("+")
b, c = r.split("=")
a = len(a)
b = len(b)
c = len(c)
if a+b == c+2:
    if a > b:
        a -= 1
    else:
        b -= 1
    c += 1
elif a+b == c-2:
    c -= 1
    a += 1
if a+b == c:
    print("|"*a + "+" + "|"*b + "=" + "|"*c)
else:
    print("Impossible")
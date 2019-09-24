a = int(input())
b = int(input())
c = int(input())

if a == 1:
    if c == 1:
        print(a+b+c)
    else:
        print((a+b)*c)
elif b == 1:
    print(max((a+1)*c, a*(c+1)))
elif c == 1:
    print(a*(b+1))
else:
    print(a*b*c)
n = int(input())
a = []
a = input().split()
ilist = [n*int("0".join(s)+"0") for s in a]
jlist = [n*int("0".join(s)) for s in a]
res = sum(ilist)+sum(jlist)
print(res % 998244353)
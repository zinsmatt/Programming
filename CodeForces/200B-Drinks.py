n = int(input())
s = sum(list(map(lambda x: float(x) / 100.0, input().split())))
print("%.04f" % (100 * s / n))
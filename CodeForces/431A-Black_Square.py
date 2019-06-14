cals = list(map(int, input().split()))
print(sum([cals[int(c)-1] for c in input()]))
n = input()
a = list(map(int, input().split()))
maxi = max(a)
print(sum([maxi - b for b in a]))
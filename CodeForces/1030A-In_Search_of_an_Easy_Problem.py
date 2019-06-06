input()
s = list(map(int, input().split()))
easy = True
for c in s:
    if c:
        easy = False
        break
if easy:
    print("EASY")
else:
    print("HARD")
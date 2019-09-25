w = input()
low = sum([1 if c.islower() else 0 for c in w])
if low >= len(w)/2:
    print(w.lower())
else:
    print(w.upper())
s = input()
max_count = -1
count = 1
pred = s[0]
for i in range(1, len(s)):
    if s[i] == pred:
        count += 1
    else:
        count = 1
    if count > max_count:
        max_count = count
    pred = s[i]
print("YES" if max_count >= 7 else "NO")
        

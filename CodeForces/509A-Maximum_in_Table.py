n = int(input())
col = [1]
for i in range(1, n):
    new_col = [1]
    for j in range(1, i+1):
        if j < i:
            new_col.append(col[j]+new_col[j-1])
        else:
            new_col.append(new_col[j-1]*2)
    col = new_col.copy()
print(col[-1])

    
n = int(input())
for i in range(n):
    x = int(input())
    size = 1
    for j in range(x):
        if j%2==0:
            size *= 2
        else:
            size += 1   
    print(size)

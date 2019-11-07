k = int(input())
for i in range(k):
    n = int(input())
    sa = input()
    sb = input()
    
    diff = [[], []]
    for a, b in zip(sa, sb):
        if a != b:
            diff[0].append(a)
            diff[1].append(b)
    N = len(diff[0])
    if N == 0:
        print("Yes")
    elif N == 2:
        if diff[0][0] == diff[0][1] and diff[1][1] == diff[1][0]:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
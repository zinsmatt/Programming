q = int(input())
for i in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    diff = 0
    j = 0
    ok = True
    no_more = False
    while j < n:
        if a[j] > b[j]:
            ok = False
            break
        if a[j] != b[j]:
            if no_more:
                ok = False
                break
            if diff == 0:
                diff = b[j] - a[j]
            else:
                if diff != b[j] - a[j]:
                    ok = False
                    break
        else:
            if diff != 0:
                no_more = True
        j += 1
    if ok:
        print("YES")
    else:
        print("NO")
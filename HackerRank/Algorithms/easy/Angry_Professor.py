t = int(input())
for i in range(t):
    n, k = input().split()
    n = int(n)
    k = int(k)
    nb_pres = 0
    for j in input().split():
        if int(j) <=0:
            nb_pres+=1
    if nb_pres<k:
        print("YES")
    else:
        print("NO")
   
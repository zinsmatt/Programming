    q = int(input())
     
    for i in range(q):
        n = int(input())
        a = list(map(int, input().split()))
        
        l = 0
        
        while l < n-1:
            idx = a.index(min(a[l:]), l)
            if idx == l:
                l = idx+1
                continue
            mini = a[idx]
            #print("mini = ", mini)
            a[l+1:idx+1] = a[l:idx]
            a[l] = mini
            #print("a = ", a)
            
            l = idx
        print(" ".join(map(str, a)))
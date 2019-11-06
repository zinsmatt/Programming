k = int(input())
for q in range(k):
    n = int(input())
    sa = list(input())
    sb = list(input())
    
    occ = [0]*26
    for c in sa:
        occ[ord(c) - ord('a')] += 1
    for c in sb:
        occ[ord(c) - ord('a')] += 1
    ok = True
    for o in occ:
        if o % 2 != 0:
            ok = False
    if ok:
        diff = []
        for i in range(len(sa)):
            if sa[i] != sb[i]:
                diff.append(i)
        swaps = []
        for i, idx in enumerate(diff):
            #print(sa, sb)
            if sa[idx] == sb[idx]:
                continue
            
            if i == len(diff)-1:
                ok = False
                break
            look = sa[idx]
            j = i + 1
            while j < len(diff):
                if sa[diff[j]] == look:
                    break
                j += 1
            if j < len(diff):
                tmp = sa[diff[j]]
                sa[diff[j]] = sb[idx]
                sb[idx] = tmp
                swaps.append((diff[j], idx))
            else:
                j = i
                while j < len(diff):
                    if sb[diff[j]] == look:
                        break
                    j += 1
                #print("i j", i, j)
                if j < len(diff) and j != i:
                    #swap i+1 <-> j
                    tmp = sb[diff[j]]
                    sb[diff[j]] = sa[diff[i+1]]
                    sa[diff[i+1]] = tmp
                    swaps.append((diff[i+1], diff[j]))
 
                    #swap i+1 <-> i
                    tmp = sa[diff[i+1]]
                    sa[diff[i+1]] = sb[idx]
                    sb[idx] = tmp
                    swaps.append((diff[i+1], idx))
 
                else:
                    ok = False
                    break
    if ok:
        print("Yes")
        print(len(swaps))
        for s in swaps:
            print("%d %d" % (s[0]+1, s[1]+1))
    else:
        print("No")
        
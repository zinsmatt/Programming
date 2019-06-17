n, p, k = list(map(int, input().split()))
pages = range(max(1, p-k), min(p+k+1,n+1))
pre, suf = "<< ", " >>"
if pages[0] == 1:
    pre = ""
if pages[-1] == n:
    suf = ""
pages = list(map(str, pages))
for i in range(len(pages)):
    if pages[i] == str(p):
        pages[i] = "(" + pages[i] + ")"
print(pre + " ".join(map(str, pages))  + suf)

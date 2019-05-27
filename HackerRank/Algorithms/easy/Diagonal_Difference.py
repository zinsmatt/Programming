n = int(input())


i=0
d1=0
d2=0
for i in range(n):
    l = input()
    s = l.split(" ")
    d1+=int(s[i])
    d2+=int(s[-1-i])
  
print(abs(d1-d2))

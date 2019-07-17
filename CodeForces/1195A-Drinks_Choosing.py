import math
 
n, k = list(map(int, input().split()))
a = []
o = [0]*k
for i in range(n):
    x = int(input())
    a.append(x)
    o[x-1]+=1
nb_pairs = 0
for z in o:
    nb_pairs += z // 2
#print("nb pairs = ", nb_pairs)
 
r = n - nb_pairs * 2
t = int(math.ceil(n/2))
#print("t=", t)
t -= nb_pairs
print(n - (r - t))
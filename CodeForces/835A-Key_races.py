s, v1, v2, t1, t2 = list(map(int, input().split()))
a = s*v1+2*t1
b = s*v2+2*t2
if a < b:
    print("First")
elif a > b:
    print("Second")
else:
    print("Friendship")
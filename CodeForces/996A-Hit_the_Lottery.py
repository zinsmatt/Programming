n = int(input())
bills = [1, 5, 10, 20, 100]
res = 0
a = 4
while n > 0:
    res += n // bills[a]
    n = n % bills[a]
    a -= 1
    
print(res)
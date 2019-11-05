a, b = list(map(int, input().split()))

num = 6-max(a, b)+1
den = 6
if num % 2 == 0:
    num /= 2
    den /= 2
    
if den % num == 0:
    den /= num
    num /= num
    

print("%d/%d" % (num, den))
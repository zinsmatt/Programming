# Enter your code here. Read input from STDIN. Print output to STDOUT
import math as m
p = 0.12
q = 1.0 - p

def x_parmi_10(x):
    return m.factorial(10) / (m.factorial(x)*m.factorial(10-x))

p1 = 0
p1 += x_parmi_10(0) * p**0 * q ** 10
p1 += x_parmi_10(1) * p**1 * q ** 9
p2 = p1
p1 += x_parmi_10(2) * p**2 * q ** 8
print("%.3f" % p1)

print("%.3f" % (1.0 - p2))
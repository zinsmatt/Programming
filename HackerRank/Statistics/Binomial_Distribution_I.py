# Enter your code here. Read input from STDIN. Print output to STDOUT
import math as m
p = 1.09 / 2.09
q = 1.0 / 2.09

def binomial(x):
    r = m.factorial(6) / (m.factorial(x) * m.factorial(6-x))
    r *= p**x * q**(6-x)
    return r
print("%.3f" % (1.0 - (binomial(0) + binomial(1) + binomial(2))))
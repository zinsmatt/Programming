# Enter your code here. Read input from STDIN. Print output to STDOUT
import math as m

def f(x, mu, std):
    return 0.5*(1+m.erf((x-mu)/(std*m.sqrt(2))))


n = 49
mu = 205
std = 15

mu2 = n * 205
std2 = m.sqrt(n) * 15

print("%.4f" % (f(9800, mu2, std2)))
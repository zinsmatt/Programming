# Enter your code here. Read input from STDIN. Print output to STDOUT
import math as m

def f(x, mu, std):
    return 0.5*(1+m.erf((x-mu)/(std*m.sqrt(2))))

mu2 = 100 * 2.4
std2 = m.sqrt(100) * 2.0

print("%.4f" % f(250, mu2, std2))
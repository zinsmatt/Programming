# Enter your code here. Read input from STDIN. Print output to STDOUT

import math as m

def f(x, mean, std):
    return 0.5*(1+m.erf((x-mean)/(std*m.sqrt(2))))


print("%.2f" % (100*(1.0 - f(80, 70, 10))))
a = (1.0 - f(60, 70, 10))
print("%.2f" % (100*a))
print("%.2f" % (100*(1.0-a)))


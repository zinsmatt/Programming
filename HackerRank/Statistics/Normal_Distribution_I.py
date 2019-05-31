# Enter your code here. Read input from STDIN. Print output to STDOUT

import math as m

def cummulative(x, mean, std):
    return 0.5*(1+m.erf((x-mean)/(std*m.sqrt(2))))

print("%.3f" % cummulative(19.5, 20, 2))
print("%.3f" % (cummulative(22, 20, 2) - cummulative(20, 20, 2)))
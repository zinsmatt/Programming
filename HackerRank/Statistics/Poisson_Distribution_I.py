# Enter your code here. Read input from STDIN. Print output to STDOUT
import math as m

mean = 2.5
k = 5
print("%.3f" % ((mean**k)*m.exp(-mean)/m.factorial(k)))

#!/bin/python3

import os
import sys

#
# Complete the timeConversion function below.
#
def timeConversion(s):
    #
    # Write your code here.
    #
    h, m, s = s.split(":")
    c = s[2:]
    s = s[:2]
    h = int(h)
    if c == "AM":
        h = h % 12
    else:
        h = h % 12 + 12
    return "%02d:%02d:%02d" % (h, int(m), int(s))

if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = timeConversion(s)

    f.write(result + '\n')

    f.close()

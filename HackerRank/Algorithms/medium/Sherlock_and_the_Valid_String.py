#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    # Write your code here
    count = [0] * 26
    for c in s:
        count[ord(c)-ord('a')] += 1
    d = {}
    for n in count:
        if n > 0:
            if n in d.keys():
                d[n] += 1
            else:
                d[n] = 1
    print(d)
    if len(d.keys()) == 1:
        return "YES"
    if len(d.keys()) == 2:
        for n, nb in d.items():
            if n == 1 and nb == 1:
                return "YES"
        M, m = max(d.keys()), min(d.keys())
        if d[M] == 1 and M == m+1:
            return "YES"
    return "NO"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()


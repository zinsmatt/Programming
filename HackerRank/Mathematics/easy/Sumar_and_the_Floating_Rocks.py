#!/bin/python3

import os
import sys


def pgcd(a, b):
    if b != 0:
        return pgcd(b, a%b)
    else:
        return a
# Complete the solve function below.
def solve(x1, y1, x2, y2):
    if x1 == x2 and y1 == y2:
        return 0
    elif y1 == y2:
        return abs(x1-x2)-1
    elif x1 == x2:
        return abs(y1-y2)-1
    else:
        return pgcd(abs(x1-x2), abs(y1-y2)) - 1
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input())

    for t_itr in range(t):
        x1Y1X2Y2 = input().split()

        x1 = int(x1Y1X2Y2[0])

        y1 = int(x1Y1X2Y2[1])

        x2 = int(x1Y1X2Y2[2])

        y2 = int(x1Y1X2Y2[3])

        result = solve(x1, y1, x2, y2)

        fptr.write(str(result) + '\n')

    fptr.close()

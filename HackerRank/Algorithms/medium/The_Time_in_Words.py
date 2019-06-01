#!/bin/python3

import math
import os
import random
import re
import sys

nw=["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine" ]

# Complete the timeInWords function below.
def timeInWords(h, m):
    if (m == 0):
        return nw[h] + " o' clock"
    else:
        if m <= 30:
            mid = "past"
            past = nw[h]
        else:
            mid = "to"
            past = nw[h+1]
        if m == 15 or m == 45:
            pre = "quarter"
        elif m == 30:
            pre = "half"
        else:
            if m < 30:
                pre = nw[m]
            else:
                pre = nw[60-m]
            if m == 1 or m == 59:
                pre += " minute"
            else:
                pre += " minutes"
        
        return " ".join([pre, mid, past])

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    h = int(input())

    m = int(input())

    result = timeInWords(h, m)

    fptr.write(result + '\n')

    fptr.close()

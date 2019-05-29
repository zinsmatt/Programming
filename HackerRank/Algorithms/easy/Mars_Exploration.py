#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the marsExploration function below.
def marsExploration(s):
    count = 0
    for i in range(len(s)):
        if i % 3 == 0 and s[i] != 'S':
            count += 1
        elif i % 3 == 1 and s[i] != 'O':
            count += 1
        elif i % 3 == 2 and s[i] != 'S':
            count += 1
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = marsExploration(s)

    fptr.write(str(result) + '\n')

    fptr.close()

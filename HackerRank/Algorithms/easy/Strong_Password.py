#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the minimumNumber function below.
def minimumNumber(n, password):
    # Return the minimum number of characters to make the password strong
    n_digits = 0
    n_low = 0
    n_up = 0
    n_spe = 0
    for c in password:
        if c in "0123456789":
            n_digits += 1
        elif c in "abcdefghijklmnopqrstuvwxyz":
            n_low += 1
        elif c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            n_up += 1
        elif c in "!@#$%^&*()-+":
            n_spe += 1
    n = 0
    if n_digits == 0:
        n += 1
    if n_low == 0:
        n += 1
    if n_up == 0:
        n += 1
    if n_spe == 0:
        n += 1
    return max(6-len(password), n)
        
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    password = input()

    answer = minimumNumber(n, password)

    fptr.write(str(answer) + '\n')

    fptr.close()

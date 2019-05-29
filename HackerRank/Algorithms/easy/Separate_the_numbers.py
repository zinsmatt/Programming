#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the separateNumbers function below.
def separateNumbers(s):
    for size in range(1, len(s)//2+1):
        x = int(s[:size])
        init_x = x
        a = size
        ok = True
        while a < len(s):
            new_size = len(str(x+1))
            if a + new_size > len(s):
                ok = False
                break
            if int(s[a:a+new_size]) == x+1:
                x = x + 1
                a = a + new_size
            else:
                ok = False
                break
        if ok:
            print("YES", init_x)
            return
    print("NO")

if __name__ == '__main__':
    q = int(input())

    for q_itr in range(q):
        s = input()

        separateNumbers(s)

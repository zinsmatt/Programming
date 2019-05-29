#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the insertionSort2 function below.
def insertionSort2(n, arr):
    for i in range(1, n):
        left = sorted(arr[:i+1])
        nouv = left + arr[i+1:]
        arr = nouv
        print(" ".join(map(str, arr)))

         
if __name__ == '__main__':
    n = int(input())

    arr = list(map(int, input().rstrip().split()))

    insertionSort2(n, arr)

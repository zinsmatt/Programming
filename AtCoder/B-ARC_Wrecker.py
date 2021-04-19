#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Apr 17 09:21:00 2021

@author: mzins
"""
import math


# I = "314 159 265 358 979 323 846"
n = input()
l = set(map(int, input().split()))

P = 10**9+7

l = sorted(l)[::-1] + [0]
x = 1
for i in range(1, len(l), 1):
    p = l[i-1]-l[i]+1    
    x *= p
print(x % P)


#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
@author: Matthieu Zins

"""




def bin_search_h1(l, r):
    if r-l == 1:
        return l
    else:
        m = (l+r) // 2
        print(m, 0)
        rep = input()
        if rep == "HIT":
            return bin_search_h1(m, r)
        else:
            return bin_search_h1(l, m)
        
def bin_search_h2(l, r):
    if r-l == 1:
        return r
    else:
        m = (l+r) // 2
        print(m, 0)
        rep = input()
        if rep == "HIT":
            return bin_search_h2(l, m)
        else:
            return bin_search_h2(m, r)




def bin_search_v1(l, r):
    if r-l == 1:
        return l
    else:
        m = (l+r) // 2
        print(0, m)
        rep = input()
        if rep == "HIT":
            return bin_search_v1(m, r)
        else:
            return bin_search_v1(l, m)
        
def bin_search_v2(l, r):
    if r-l == 1:
        return r
    else:
        m = (l+r) // 2
        print(0, m)
        rep = input()
        if rep == "HIT":
            return bin_search_v2(l, m)
        else:
            return bin_search_v2(m, r)


import sys

T, A, B = map(int, input().split())
# print(T, A, B, file=sys.stderr)
# T = 1
# A = 10**9-5
# B = 10**9-5


for tti in range(T):
    good = False
    
    max_shift = (10**9-A)*2
    x1 = bin_search_h1(10**9-max_shift, 10**9)
    x2 = bin_search_h2(-10**9, -10**9+max_shift)
    
    y1 = bin_search_v1(10**9-max_shift, 10**9)
    y2 = bin_search_v2(-10**9, -10**9+max_shift)
    
    
    # y = 0
    # x = -10**9
    # while 1:
    #     print(x, y)
    #     rep = input()
    #     if rep == "HIT":
    #         break
    #     x += 1
    # x1 = x
    
    # x = 10**9
    # while 1:
    #     print(x, y)
    #     rep = input()
    #     if rep == "HIT":
    #         break
    #     x -= 1
    # x2 = x
        
    # print("x1 = ", x1, file=sys.stderr)
    # print("x2 = ", x2, file=sys.stderr)
    center_x = (x1+x2) / 2
    
    
    
    # x = 0
    # y = -10**9
    # while 1:
    #     print(x, y)
    #     rep = input()
    #     if rep == "HIT":
    #         break
    #     y += 1
    # y1 = y
    
    # y = 10**9
    # while 1:
    #     print(x, y)
    #     rep = input()
    #     if rep == "HIT":
    #         break
    #     y -= 1
    # y2 = y
    
    center_y = (y1 + y2) / 2
    xx = int(round(center_x))
    yy = int(round(center_y))
    
   

    for dy in range(-1, 2):
        for dx in range(-1, 2):
            print(xx+dx,yy+dy)  
            # print(xx+dx,yy+dy, file=sys.stderr)  
            rep = input()
            if rep == "CENTER":
                good = True
                break
        if good:
            break




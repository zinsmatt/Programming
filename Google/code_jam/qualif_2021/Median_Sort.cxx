#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Mar 27 13:00:00 2021

@author: mzins
"""
import sys
import numpy as np
import random
# np.random.seed(1994)
# random.seed(1994)
N = 10
l = list(range(1, N+1))

random.shuffle(l)

def median(l):
    return sorted(l)[len(l)//2]

def solve(l):
    remove = []
    ops = 0
    for i in range(len(l)):
        a = [x for x in l if x not in remove]
        # med = median(a)
        med= med_of_med(a)
        # ops += op
        remove.append(med)
    # print("ops = ", ops)
    res = []
    for j in range(len(remove)):
        if j % 2:
            res = [remove[j]] + res
        else:
            res += [remove[j]]
    return res


def med_of_med(l):
    if len(l) <= 5:
        return median(l)
    if len(l) == 1:
        return l[0]
    
    med_list = []
    op = 0
    for i in range(0, len(l), 3):
        op += 1
        sub = l[i:i+3]
        sub = sorted(sub)
        m = sub[len(sub)//2]
        med_list.append(m)
    # print("op=", op)
    return med_of_med(med_list)


# ret = solve(l)
# print("ret = ", ret)


# ret = med_of_med(l)
# print(ret)

OP = 0
def median_idx(a, b, c):    
    # global OP, l
    # OP += 1
    # sub = [l[a], l[b], l[c]]
    # s = np.argsort(sub)
    # return [a, b, c][s[1]]
    # # return np.argsort(l)[1]
    print(a+1, b+1, c+1, flush=True)
    res = int(input())
    return res-1

# l = ret

def f(l):
    print(l)
    for j in range(len(l)):
        for i in range(0, len(l)-3, 1):
            m_i = median_idx(l[i:i+3])
            if m_i != 1:
                l[i+m_i], l[i+1] = l[i+1], l[i+m_i]
            # print(l)
    print(l)
    
# f(l)


def ff(n):
    # print(l)
    counts = [0] * n
    for i in range(n):
        for j in range(i+1, n):
            for k in range(j+1, n):
                # indices = [i, j, k]
                # m = median_idx([l[i], l[j], l[k]])
                m_i = median_idx(i, j, k)

                # m_i = indices[m]
                counts[m_i] += 1
                
                
    # print(counts)
    sorted_indices = np.argsort(counts)
    res = [0] * n
    # print(sorted_indices)
    for i in range(len(sorted_indices)//2):
        if i == 0:
            res[i] = sorted_indices[i*2]
            res[n-1-i] = sorted_indices[i*2+1]
        else:
            a = sorted_indices[i*2]
            b = sorted_indices[i*2+1]
            c = sorted_indices[i*2-2]
            # print("sel: ", a, b, c)
            # m_i = median_idx([l[c], l[a], l[b]])
            m_i = median_idx(c, a, b)#[l[c], l[a], l[b]])
            # print(c, a, b, "==>", m_i)
            # print("median is at idx = ", m_i)
            if m_i == a:
                res[i] = a
                res[n-1-i] = b
            else:
                res[i] = b
                res[n-1-i] = a
                sorted_indices[i*2], sorted_indices[i*2+1] = sorted_indices[i*2+1], sorted_indices[i*2]

    res = list(map(lambda x: x+1, res))
    
    # print(*res, flush=True, file=sys.stderr)
    print(*res, flush=True)
    
    result = input()
    #print("result = ", result, file=sys.stderr, flush=True)
    
    # global l
    # final = [l[x] for x in res]
    # print(final)
    
    
# ff(len(l))
# print("NB OPS = ", OP)

T, N, Q = map(int, input().split())
# print(T, N, Q, file=sys.stderr)

for ti in range(T):
    ff(N)
    
    

s = input()
n = s.count('a')
n_other = len(s) - n
if n > n_other:
    print(len(s))
else:
    print(len(s)-(1+n_other-n))
s = input()
a = 0
while a < len(s) and s[a] != 'v':
    a += 1
    
if a >= len(s):
    print(0)
else:
    total = 0
    nouv = ""
    nb_v = 0
    for i in range(len(s)):
        if s[i] == 'o':
            if nb_v > 1:
                nouv += "v" * (nb_v - 1)
                total += nb_v-1
            nb_v = 0
            nouv += "o"
        else:
            nb_v += 1
    if nb_v > 1:
        nouv += "v" * (nb_v - 1)
        total += nb_v-1
    nb_v = 0
    res = 0
    for c in nouv:
        if c == 'v':
            nb_v += 1
        else:
            res += nb_v * (total-nb_v)
    print(res)
n = int(input())
s = input()
nb_1 = sum(list(map(int, list(s))))
nb_0 = len(s) - nb_1
 
if nb_0 != nb_1:
    print(1)
    print(s)
else:
    if len(s) == 1:
        print(1)
        print(s)
    elif len(s) == 2:
        if s[0] == s[1]:
            print(1)
            print(s)
        else:
            print(2)
            print(s[0], s[1])
    else:
        if abs(nb_0-nb_1) > 1 or nb_0 == nb_1:
            print(2)
            print(s[0], s[1:])
        else:
            print(3)
            print(s[0], s[1], s[2:])
        
 
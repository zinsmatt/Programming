n = int(input())
s = 0
for i in range(n):
    p = input()
    if p == "Tetrahedron":
        s += 4
    elif p == "Cube":
        s += 6
    elif p == "Octahedron":
        s += 8
    elif p == "Dodecahedron":
        s += 12
    elif p == "Icosahedron":
        s += 20
print(s)
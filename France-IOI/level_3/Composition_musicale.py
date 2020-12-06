s=input()
r = ""
for c in s:
   if len(r) == 0:
      r += c
   else:
      if r[-1] == c:
         r = r[:-1]
      else:
         r += c
print(r)


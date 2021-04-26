n = int(input())

for ni in range(n):
	s = input()


	res = ""
	d = 0
	for c in s:
		diff = int(c) - d
		if diff == 0:
			res += c
		elif diff > 0:
			res += "(" * diff 
			res += c
		else:
			res += ")" * abs(diff)
			res += c
		d += diff
	res += ")" * d

	print("Case #%d:" % (ni+1), res)

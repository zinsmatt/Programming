n = int(input())
n_two = n // 2
n_three = 0
if n % 2 == 1:
    n_two -= 1
    n_three += 1
print(n_two + n_three)
print(" ".join((["2"]*n_two) + (["3"]*n_three)))

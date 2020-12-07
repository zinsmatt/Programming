n = int(input())


instructions = []

def flip(x, i):
    instructions.append(i+1)
    x[i] = (x[i]+1)%2
    

def f(x, i):
    if i >= 2:
        if x[:i] == (i-2)*[0]+[1]:
            flip(x, i)
            return x
        else:
            if x[i-1] != 1:
                x = f(x, i-1)
            j = i-2
            while j >= 0:
                if x[j] == 1:
                    x = f(x, j)
                j -= 1
            flip(x, i)
            return x
    elif i == 1:
        if x[0] == 0:
            x = f(x, 0)
            
        flip(x, 1)
        return x
    else:
        flip(x, 0)
        return x
    
    
arr = [1] * n

for i in range(n-1, -1, -1):
    if arr[i]:
        arr = f(arr, i)

for x in instructions:
    print(x)

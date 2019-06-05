n = int(input())
sentiments = ["I hate", "I love"]
s = []
for i in range(n):
    s.append(sentiments[i%2])
print(" that ".join(s) + " it")
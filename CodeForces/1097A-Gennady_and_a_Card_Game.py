card = input()
rank = card[0]
suit = card[1]

cards = input().split(" ")
ranks = []
suits = []
for c in cards:
    ranks.append(c[0])
    suits.append(c[1])
if rank in ranks or suit in suits:
    print("YES")
else:
    print("NO")
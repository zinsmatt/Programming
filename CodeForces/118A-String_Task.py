print("".join(["."+c.lower() if c not in "aeiouy" and c not in "AEIOUY" else "" for c in input()]))

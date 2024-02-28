class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        counts = {"A" : 0, "B" : 0}
        prev = ""
        l = 1
        for c in colors:
            if len(prev) > 0:
                if c == prev:
                    l += 1
                else:
                    if l > 2:
                        counts[prev] += l - 2
                    l = 1
            prev = c
        if l > 2:
            counts[prev] += l - 2
        return counts["A"] > counts["B"]

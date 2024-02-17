class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        nb_lost = {}
        for a, b in matches:
            if b in nb_lost.keys():
                nb_lost[b] += 1
            else:
                nb_lost[b] = 1
        
            if a not in nb_lost.keys():
                nb_lost[a] = 0
        
        no_lost = []
        one_lost = []
        for i, n in nb_lost.items():
            if n == 0:
                no_lost.append(i)
            if n == 1:
                one_lost.append(i)
        return [sorted(no_lost), sorted(one_lost)]
        

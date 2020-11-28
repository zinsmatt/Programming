def rem(l, indices):
    b=0
    for i in sorted(indices):
        del l[i-b]
        b += 1
    return l

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        a = sorted(people)
        n = len(a)
        res = [[] for i in range(n)]
        av = list(range(n))
        
        
        prev = a[0][0]
        to_rm = []
        for i in range(n):
            if a[i][0] != prev:
                av = rem(av, to_rm)
                to_rm = []
                prev = a[i][0]

            index = av[a[i][1]]
            res[index] = a[i]
            to_rm.append(a[i][1])

        return res
            

def transf(s):
    s1 = s[::2]
    s2 = s[1::2]
    return "".join(sorted(s1) + sorted(s2))

class Solution:
    def numSpecialEquivGroups(self, A: List[str]) -> int:
        d = {}
        for s in A:
            ss = transf(s)
            if ss in d.keys():
                d[ss] += 1
            else:
                d[ss] = 1
        return len(d.keys())
                    
        

import itertools

def w_score(w, score):
    return  sum(score[ord(c)-ord('a')] for c in w)
    
def count(l):
    L = "".join(l)
    return [L.count(chr(ord('a')+i)) for i in range(26)]
    
def valid(c1, c2):
    for a, b in zip(c1, c2):
        if a < b:
            return False
    return True


class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:
        count_init = count(letters)
        
        scores = [w_score(w, score) for w in words]
        res = 0
        
        
        for n in range(1, len(words)+1):
            for combi in itertools.combinations(range(len(words)), r=n):
                selected = [words[i] for i in combi]
                c = count(selected)
                if valid(count_init, c):
                    s = sum(scores[i] for i in combi)
                    res = max(res, s)
        
        
        return res

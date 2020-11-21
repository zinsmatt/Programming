import itertools

class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        self.iter = itertools.combinations(characters, combinationLength)
        n = len(characters)
        self.nb = math.factorial(n) / (math.factorial(combinationLength) * math.factorial(n - combinationLength))
        
    def next(self) -> str:
        self.nb -= 1
        return "".join(next(self.iter))
        

    def hasNext(self) -> bool:
        return self.nb > 0
        
        


# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()

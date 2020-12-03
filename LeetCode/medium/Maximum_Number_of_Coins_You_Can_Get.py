class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        a = sorted(piles)[::-1]
        return sum(a[1:-len(a)//3:2])

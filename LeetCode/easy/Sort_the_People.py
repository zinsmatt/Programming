class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [names[i] for i in sorted(range(len(names)), key=lambda x : heights[x], reverse=True)]

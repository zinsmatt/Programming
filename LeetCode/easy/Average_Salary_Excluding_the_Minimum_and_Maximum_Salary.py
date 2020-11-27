class Solution:
    def average(self, salary: List[int]) -> float:
        s = sorted(salary)
        return sum(s[1:-1]) / (len(s)-2)

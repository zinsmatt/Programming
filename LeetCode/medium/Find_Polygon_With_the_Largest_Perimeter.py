class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums = sorted(nums)
        s = [nums[0]]
        for i in range(1, len(nums)):
            s.append(s[-1] + nums[i])
        i = len(nums) - 1
        while i >= 2:
            if nums[i] < s[i - 1]:
                return s[i]
            i -= 1
        return -1


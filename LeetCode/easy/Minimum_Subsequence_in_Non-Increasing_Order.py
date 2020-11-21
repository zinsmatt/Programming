class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        s = sum(nums)
        nums = sorted(nums, reverse=True)
        x = nums[0]
        idx = 0
        while x <= s-x:
            idx += 1
            x += nums[idx]
        return nums[:idx+1]

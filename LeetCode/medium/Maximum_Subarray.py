class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        res = -111111111111
        l = 0
        r = 0

        while l < len(nums):
            r = l
            s = 0
            while r < len(nums) and s >= 0:
                s += nums[r]
                res = max(res, s)
                r += 1
            l = r
        return res



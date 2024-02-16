class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        nums = sorted(nums)
        return max(nums[i]+nums[-1-i] for i in range(len(nums)//2))


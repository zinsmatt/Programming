class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = len(nums)
        for i, x in enumerate(nums):
            res ^= x
            res ^= i
        return res


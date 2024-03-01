class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        counts = [0, 0, 0]
        for c in nums:
            counts[c] += 1
        s1 = counts[0]
        s2 = counts[0] + counts[1]
        for i in range(len(nums)):
            if i < s1:
                nums[i] = 0
            elif i < s2:
                nums[i] = 1
            else:
                nums[i] = 2

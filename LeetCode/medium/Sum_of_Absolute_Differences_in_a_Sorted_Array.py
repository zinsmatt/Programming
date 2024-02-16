class Solution:
    def getSumAbsoluteDifferences(self, nums: List[int]) -> List[int]:
        left = [0] * len(nums)
        right = [0] * len(nums)
        for i in range(1, len(nums)):
            left[i] = left[i-1] +  i * (nums[i]-nums[i-1])

        for i in range(len(nums)-2, -1, -1):
            right[i] = right[i+1] + (len(nums)-1-i) * (nums[i+1]-nums[i])
        
        return [a+b for (a, b) in zip(left, right)]


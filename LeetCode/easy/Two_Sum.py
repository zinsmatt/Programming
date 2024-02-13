class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        sorted_nums = sorted(enumerate(nums), key=lambda x : x[1])

        l = 0
        r = len(nums) - 1
        while l < r:
            s = sorted_nums[l][1] + sorted_nums[r][1]
            if s == target:
                return sorted_nums[l][0], sorted_nums[r][0]
            elif s < target:
                l += 1
            else:
                r -= 1


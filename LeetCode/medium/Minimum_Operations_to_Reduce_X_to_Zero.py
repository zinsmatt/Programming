class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        sum_left = {}
        s = 0
        for i in range(len(nums)):
            s += nums[i]
            sum_left[s] = i
        sum_right = {}
        s = 0
        for i in range(len(nums)-1, -1, -1):
            s += nums[i]
            sum_right[s] = i
        # print(sum_left)
        # print(sum_right)
        res = 9999999
        s = 0
        for i in range(len(nums)):
            s += nums[i]
            r = x - s
            if r == 0:
                res = min(res, i+1)
            elif r in sum_right.keys() and sum_right[r] > i:
                res = min(res, (i+1) + len(nums)-sum_right[r])
        s = 0
        for i in range(len(nums)-1, -1, -1):
            s += nums[i]
            r = x - s
            if r == 0:
                res = min(res, len(nums)-i)
            elif r in sum_left.keys() and sum_left[r] < i:
                res = min(res, len(nums)-i + sum_left[r]+1)
        
        if res > len(nums):
            res = -1
        return res



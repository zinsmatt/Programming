def check(arr):
    return all(arr[i+1]-arr[i] == arr[1]-arr[0] for i in range(1, len(arr)-1))
        
class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []
        for left, right in zip(l, r):
            res.append(check(sorted(nums[left:right+1])))
        
        return res

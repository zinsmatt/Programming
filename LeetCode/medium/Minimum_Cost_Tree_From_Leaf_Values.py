class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        res = 0
        while len(arr):
            mini = 999999999999
            mini_idx = 0
            for i in range(len(arr)-1):
                if arr[i]*arr[i+1] < mini:
                    mini = arr[i]*arr[i+1]
                    mini_idx = i
            res += mini
            if len(arr) > 2:
                arr = arr[:mini_idx] + [max(arr[mini_idx], arr[mini_idx+1])] + arr[mini_idx+2:]
            else:
                break    
        return res
            

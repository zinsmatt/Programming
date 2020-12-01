class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        maxi = [-1] * (len(arr)+1)
        for i in range(len(maxi)-1-1, 0, -1):
            maxi[i] = max(maxi[i+1], arr[i])
        return maxi[1:]
            

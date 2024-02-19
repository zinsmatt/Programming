class Solution:
    def findDiagonalOrder(self, nums: List[List[int]]) -> List[int]:
        N = 1
        for i, l in enumerate(nums):
            for j, x in enumerate(l):
                N = max(N, i+j)

        A = [[] for i in range(N+1)]
        for i, l in enumerate(nums):
            for j, x in enumerate(l):
                A[i+j].append(x)
        return chain(*map(lambda x:x[::-1], A))



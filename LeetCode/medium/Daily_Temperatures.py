class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        s = []
        n = len(temperatures)
        res = [0] * n
        for i, t in enumerate(temperatures):
            while len(s) > 0 and temperatures[s[-1]] < t:
                ind = s[-1]
                s.pop(-1)
                res[ind] = i-ind
            s.append(i)
        return res

        # n = len(temperatures)
        # MAX = n+3
        # a = [[MAX]*101 for i in range(n)]
        # for i in range(n-2, -1, -1):
        #     for j in range(101):
        #         a[i][j] = a[i+1][j]
        #     a[i][temperatures[i+1]] = i+1

        # res = []
        # for i in range(n):
        #     ind = MAX
        #     higher_temp_ind = [a[i][k] for k in range(temperatures[i]+1, 101)]
        #     if len(higher_temp_ind) > 0:
        #         ind = min(higher_temp_ind)
        #     if ind == MAX:
        #         ind = 0
        #     else:
        #         ind = ind-i
        #     res.append(ind)
        # return res


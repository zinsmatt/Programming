class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        # def hash(l):
        #     a = [0] * 41
        #     for x in l:
        #         a[x] += 1
        #     return "-".join(map(str, a))
        # rec = set()
        # res = []
        # def solve(cur, r):
        #     h = hash(cur)
        #     if h in rec:
        #         return
        #     rec.add(h)
        #     if r == 0:
        #         res.append(cur)
        #     elif r > 0:
        #         for x in candidates:
        #             solve(cur + [x], r-x)
        # solve([], target)
        # return res
        candidates = sorted(candidates)
        res = []
        def solve(i, cur, cur_sum):
            if i >= len(candidates):
                return
            if cur_sum + candidates[i] == target:
                res.append(cur + [candidates[i]])
            elif cur_sum + candidates[i] < target:
                solve(i, cur + [candidates[i]], cur_sum + candidates[i])
                solve(i+1, cur, cur_sum)
            else:
                solve(i+1, cur, cur_sum)
        solve(0, [], 0)
        return res


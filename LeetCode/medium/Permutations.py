class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        def generate(l):
            if len(l) == 0:
                return []
            elif len(l) == 1:
                return [l]
            else:
                res = []
                for i, x in enumerate(l):
                    newlist = [x]
                    restlist = l[:i] + l[i+1:]
                    suffixlist = generate(restlist)
                    for s in suffixlist:
                        res.append([x] + s)
                return res
        return generate(nums)
